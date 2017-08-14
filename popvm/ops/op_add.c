//
// ADD - 0x17
//
#ifndef ADD_C_
#define ADD_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'ADD' (0x17)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'ADD' (0x17) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
