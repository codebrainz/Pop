//
// LINE - 0x2D
//
#ifndef LINE_C_
#define LINE_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'LINE' (0x2D)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'LINE' (0x2D) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
