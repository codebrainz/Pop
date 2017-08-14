//
// LOR - 0x1F
//
#ifndef LOR_C_
#define LOR_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'LOR' (0x1F)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'LOR' (0x1F) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
