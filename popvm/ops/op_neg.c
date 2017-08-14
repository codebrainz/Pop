//
// NEG - 0x12
//
#ifndef NEG_C_
#define NEG_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'NEG' (0x12)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'NEG' (0x12) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
