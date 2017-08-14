//
// EQ - 0x27
//
#ifndef EQ_C_
#define EQ_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'EQ' (0x27)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'EQ' (0x27) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
