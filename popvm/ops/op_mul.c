//
// MUL - 0x19
//
#ifndef MUL_C_
#define MUL_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'MUL' (0x19)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'MUL' (0x19) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
