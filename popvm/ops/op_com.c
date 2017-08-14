//
// COM - 0x2C
//
#ifndef COM_C_
#define COM_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'COM' (0x2C)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'COM' (0x2C) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
