#ifdef HAVE_CONFIG_H
#include <Pop/Config.h>
#endif

#include <Pop/InstructionOptimizer.hpp>
#include <Pop/Instructions.hpp>

namespace Pop {

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
          // discard instruction following an unconditional jump which
          // preceed a label, as they're unreachable
          else {
            size_t j;
            for (j = i + 1; j < instructions.size(); j++) {
              auto &in = instructions[j];
              if (!isa< LabelInstruction * >(in.get()))
                instructions[j] = nullptr;
            }
            i = j;
            continue;
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

  // namespace Pop
}
