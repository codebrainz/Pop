//
// NOT - 0x13
//
#ifndef NOT_C_
#define NOT_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'NOT' (0x13)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'NOT' (0x13) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
