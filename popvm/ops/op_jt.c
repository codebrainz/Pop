//
// JT - 0x0D
//
#ifndef JT_C_
#define JT_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'JT' (0x0D)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'JT' (0x0D) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
