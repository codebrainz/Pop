//
// OENV - 0x08
//
#ifndef OENV_C_
#define OENV_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'OENV' (0x08)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'OENV' (0x08) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
