//
// DUP - 0x04
//
#ifndef DUP_C_
#define DUP_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'DUP' (0x04)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'DUP' (0x04) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
