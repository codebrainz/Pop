//
// LT - 0x23
//
#ifndef LT_C_
#define LT_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'LT' (0x23)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'LT' (0x23) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
