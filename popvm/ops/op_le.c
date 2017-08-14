//
// LE - 0x25
//
#ifndef LE_C_
#define LE_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'LE' (0x25)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'LE' (0x25) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
