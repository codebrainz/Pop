//
// PUSH - 0x02
//
#ifndef PUSH_C_
#define PUSH_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'PUSH' (0x02)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'PUSH' (0x02) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
