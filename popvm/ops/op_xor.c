//
// XOR - 0x22
//
#ifndef XOR_C_
#define XOR_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'XOR' (0x22)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'XOR' (0x22) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
