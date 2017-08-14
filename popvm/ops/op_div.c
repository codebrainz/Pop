//
// DIV - 0x1A
//
#ifndef DIV_C_
#define DIV_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'DIV' (0x1A)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'DIV' (0x1A) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
