//
// CLSR - 0x07
//
#ifndef CLSR_C_
#define CLSR_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'CLSR' (0x07)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'CLSR' (0x07) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
