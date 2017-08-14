//
// MOD - 0x1B
//
#ifndef MOD_C_
#define MOD_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'MOD' (0x1B)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'MOD' (0x1B) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
