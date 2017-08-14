//
// JMP - 0x0C
//
#ifndef JMP_C_
#define JMP_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'JMP' (0x0C)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'JMP' (0x0C) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
