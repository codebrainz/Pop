//
// DUP2 - 0x05
//
#ifndef DUP2_C_
#define DUP2_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'DUP2' (0x05)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'DUP2' (0x05) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
