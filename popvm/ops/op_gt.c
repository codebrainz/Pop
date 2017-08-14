//
// GT - 0x24
//
#ifndef GT_C_
#define GT_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'GT' (0x24)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'GT' (0x24) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
