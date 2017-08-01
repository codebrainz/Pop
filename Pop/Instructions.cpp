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
    for (auto &instruction : instructions) {
      instruction->offset = offset;
      offset += instruction->size();
    }

    // stash label offsets while removing label pseudo-instructions
    for (auto it = instructions.begin(); it != instructions.end();) {
      if (auto label = dynamic_cast< LabelInstruction * >((*it).get())) {
        label_offsets.emplace(label->name, label->offset);
        it = instructions.erase(it);
      } else {
        ++it;
      }
    }

    // resolve instructions which refer to labels
    for (auto &instruction : instructions) {
      if (auto closure =
              dynamic_cast< ClosureInstruction * >(instruction.get())) {
        closure->target = address_of(label_offsets, closure->name);
      } else if (auto jmp =
                     dynamic_cast< JumpInstruction * >(instruction.get())) {
        jmp->target = address_of(label_offsets, jmp->label);
      } else if (auto jmpt = dynamic_cast< JumpIfTrueInstruction * >(
                     instruction.get())) {
        jmpt->target = address_of(label_offsets, jmpt->label);
      } else if (auto jmpf = dynamic_cast< JumpIfFalseInstruction * >(
                     instruction.get())) {
        jmpf->target = address_of(label_offsets, jmpf->label);
      }
    }
  }

  // namespace Pop
}
