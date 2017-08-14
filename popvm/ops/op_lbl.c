//
// LBL - 0x2B
//
#ifndef LBL_C_
#define LBL_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'LBL' (0x2B)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'LBL' (0x2B) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
