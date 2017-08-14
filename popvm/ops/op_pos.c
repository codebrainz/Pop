//
// POS - 0x11
//
#ifndef POS_C_
#define POS_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'POS' (0x11)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'POS' (0x11) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
