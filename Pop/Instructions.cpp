#include <Pop/Instructions.hpp>
#include <Pop/ConstantsTable.hpp>
#include <cassert>
#include <unordered_map>

namespace Pop {

  typedef std::unordered_map< std::string, int > LabelOffsetTable;

  static int address_of(LabelOffsetTable &offsets, const std::string &name) {
    auto found = offsets.find(name);
    if (found != offsets.end())
      return found->second;
    return -1;
  }

  void resolve_instructions(InstructionList &instructions) {
    LabelOffsetTable label_offsets;
    int offset = 0;

    // calculate offsets
    for (auto &inst : instructions) {
      inst->offset = offset;
      offset += inst->size();
    }

    // stash label offsets while removing label pseudo-instructions
    for (auto it = instructions.begin(); it != instructions.end();) {
      if (auto label = dyn_cast< LabelInstruction * >((*it).get())) {
        label_offsets.emplace(label->name, label->offset);
        it = instructions.erase(it);
      } else {
        ++it;
      }
    }

    // resolve instructions which refer to labels
    for (auto &inst : instructions) {
      if (auto jmp = dyn_cast< JumpInstruction * >(inst.get())) {
        jmp->target = address_of(label_offsets, jmp->label);
      } else if (auto jmpt = dyn_cast< JumpIfTrueInstruction * >(inst.get())) {
        jmpt->target = address_of(label_offsets, jmpt->label);
      } else if (auto jmpf = dyn_cast< JumpIfFalseInstruction * >(inst.get())) {
        jmpf->target = address_of(label_offsets, jmpf->label);
      } else if (auto closure = dyn_cast< ClosureInstruction * >(inst.get())) {
        closure->target = address_of(label_offsets, closure->name);
      }
    }
  }

  void optimize_instructions(InstructionList &instructions) {
    for (size_t i = 0; i < instructions.size(); i++) {
      auto &inst = instructions[i];
      if (i < (instructions.size() - 1)) {
        auto &next = instructions[i + 1];
        if (auto jmp = dyn_cast< JumpInstruction * >(inst.get())) {
          // if jumping to the label directly following the jump, remove it
          if (auto lbl = dyn_cast< LabelInstruction * >(next.get())) {
            if (jmp->label == lbl->name)
              instructions[i] = nullptr;
          }
          // if an unconditional jump is followed by another unconditional
          // jump, remove it
          else if (isa< JumpInstruction * >(next.get())) {
            instructions[i] = nullptr;
          }
        } else if (isa< PushConstInstruction * >(inst.get())) {
          auto &next = instructions[i + 1];
          // if a push const is followed by a pop, remove both
          if (isa< PopInstruction * >(next.get())) {
            instructions[i] = nullptr;
            instructions[i + 1] = nullptr;
          }
        }
      }
    }
    // get rid of removed instructions
    for (auto it = instructions.begin(); it != instructions.end();) {
      auto &inst = *it;
      if (!inst)
        it = instructions.erase(it);
      else
        ++it;
    }
  }

  static void dump_constants(ConstantsTable &const_tab, std::ostream &os) {
    int i = 0;
    while (1) {
      auto n = const_tab.node(i);
      if (!n)
        break;
      os << "; " << i << ": ";
      if (dynamic_cast< Null * >(n)) {
        os << "null";
      } else if (auto bln = dyn_cast< Bool * >(n)) {
        os << (bln->value ? "true" : "false");
      } else if (auto itg = dyn_cast< Int * >(n)) {
        os << itg->value;
      } else if (auto flt = dyn_cast< Float * >(n)) {
        os << flt->value;
      } else if (auto str = dyn_cast< String * >(n)) {
        os << str->value;
      } else if (auto sym = dyn_cast< Symbol * >(n)) {
        os << sym->value;
      } else {
        assert(false);
      }
      os << '\n';
      i++;
    }
  }

  void dump_instructions(const InstructionList &instructions,
                         ConstantsTable &const_tab, std::ostream &os) {
    dump_constants(const_tab, os);
    for (auto &inst : instructions) {
      if (auto label = dyn_cast< LabelInstruction * >(inst.get())) {
        os << label->name << ":\n";
      } else if (auto cnst = dyn_cast< PushConstInstruction * >(inst.get())) {
        os << '\t' << cnst->mnemonic() << ' ' << cnst->const_id << '\n';
      } else if (auto jmp = dyn_cast< JumpInstruction * >(inst.get())) {
        os << '\t' << jmp->mnemonic() << ' ' << jmp->label << '\n';
      } else if (auto jmpt = dyn_cast< JumpIfTrueInstruction * >(inst.get())) {
        os << '\t' << jmpt->mnemonic() << ' ' << jmpt->label << '\n';
      } else if (auto jmpf = dyn_cast< JumpIfFalseInstruction * >(inst.get())) {
        os << '\t' << jmpf->mnemonic() << ' ' << jmpf->label << '\n';
      } else if (auto closure = dyn_cast< ClosureInstruction * >(inst.get())) {
        os << '\t' << closure->mnemonic() << ' ' << closure->name << '\n';
      } else {
        os << '\t' << inst->mnemonic() << '\n';
      }
    }
  }

  // namespace Pop
}
