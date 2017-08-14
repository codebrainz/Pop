//
// RSH - 0x1D
//
#ifndef RSH_C_
#define RSH_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'RSH' (0x1D)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'RSH' (0x1D) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
