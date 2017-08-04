#include <Pop/Instructions.hpp>
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
      if (auto label = (*it)->checked_cast< LabelInstruction >()) {
        label_offsets.emplace(label->name, label->offset);
        it = instructions.erase(it);
      } else {
        ++it;
      }
    }

    // resolve instructions which refer to labels
    for (auto &inst : instructions) {
      if (auto closure = inst->checked_cast< ClosureInstruction >()) {
        closure->target = address_of(label_offsets, closure->name);
      } else if (auto jmp = inst->checked_cast< JumpInstruction >()) {
        jmp->target = address_of(label_offsets, jmp->label);
      } else if (auto jmpt = inst->checked_cast< JumpIfTrueInstruction >()) {
        jmpt->target = address_of(label_offsets, jmpt->label);
      } else if (auto jmpf = inst->checked_cast< JumpIfFalseInstruction >()) {
        jmpf->target = address_of(label_offsets, jmpf->label);
      }
    }
  }

  void dump_instructions(const InstructionList &instructions,
                         std::ostream &os) {
    for (auto &inst : instructions) {
      if (auto label = inst->checked_cast< LabelInstruction >()) {
        os << label->name << ":\n";
      } else {
        os << '\t' << inst->mnemonic() << '\n';
      }
    }
  }

  // namespace Pop
}
