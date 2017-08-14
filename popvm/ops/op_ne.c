//
// NE - 0x28
//
#ifndef NE_C_
#define NE_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'NE' (0x28)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'NE' (0x28) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
