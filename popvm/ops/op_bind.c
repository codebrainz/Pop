//
// BIND - 0x0A
//
#ifndef BIND_C_
#define BIND_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'BIND' (0x0A)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'BIND' (0x0A) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
