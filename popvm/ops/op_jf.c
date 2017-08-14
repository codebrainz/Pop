//
// JF - 0x0E
//
#ifndef JF_C_
#define JF_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'JF' (0x0E)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'JF' (0x0E) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
