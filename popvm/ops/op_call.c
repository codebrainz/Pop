//
// CALL - 0x0F
//
#ifndef CALL_C_
#define CALL_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'CALL' (0x0F)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'CALL' (0x0F) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
