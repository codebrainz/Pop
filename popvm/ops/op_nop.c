//
// NOP - 0x01
//
#ifndef NOP_C_
#define NOP_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'NOP' (0x01)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'NOP' (0x01) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
