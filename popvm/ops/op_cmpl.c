//
// CMPL - 0x14
//
#ifndef CMPL_C_
#define CMPL_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'CMPL' (0x14)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'CMPL' (0x14) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
