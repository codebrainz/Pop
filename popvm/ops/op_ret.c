//
// RET - 0x10
//
#ifndef RET_C_
#define RET_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'RET' (0x10)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'RET' (0x10) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
