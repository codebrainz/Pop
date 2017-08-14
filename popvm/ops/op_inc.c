//
// INC - 0x15
//
#ifndef INC_C_
#define INC_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'INC' (0x15)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'INC' (0x15) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
