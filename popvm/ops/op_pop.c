//
// POP - 0x03
//
#ifndef POP_C_
#define POP_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'POP' (0x03)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'POP' (0x03) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
