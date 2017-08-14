//
// AND - 0x20
//
#ifndef AND_C_
#define AND_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'AND' (0x20)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'AND' (0x20) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
