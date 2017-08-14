//
// GE - 0x26
//
#ifndef GE_C_
#define GE_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'GE' (0x26)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'GE' (0x26) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
