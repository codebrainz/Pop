//
// SUB - 0x18
//
#ifndef SUB_C_
#define SUB_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'SUB' (0x18)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'SUB' (0x18) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
