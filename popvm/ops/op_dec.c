//
// DEC - 0x16
//
#ifndef DEC_C_
#define DEC_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'DEC' (0x16)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'DEC' (0x16) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
