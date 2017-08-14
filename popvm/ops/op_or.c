//
// OR - 0x21
//
#ifndef OR_C_
#define OR_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'OR' (0x21)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'OR' (0x21) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
