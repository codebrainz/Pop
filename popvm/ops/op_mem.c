//
// MEM - 0x2A
//
#ifndef MEM_C_
#define MEM_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'MEM' (0x2A)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'MEM' (0x2A) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
