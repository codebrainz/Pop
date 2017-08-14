//
// LKUP - 0x0B
//
#ifndef LKUP_C_
#define LKUP_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'LKUP' (0x0B)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'LKUP' (0x0B) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
