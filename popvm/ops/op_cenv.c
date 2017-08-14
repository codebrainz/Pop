//
// CENV - 0x09
//
#ifndef CENV_C_
#define CENV_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'CENV' (0x09)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'CENV' (0x09) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
