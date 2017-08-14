//
// HLT - 0x00
//
#ifndef HLT_C_
#define HLT_C_
#ifdef __GNUC__
#ifndef POP_NO_WARN_UNIMPLEMENTED_INSTRUCTION
#warning "Unimplemented instruction 'HLT' (0x00)"
#endif
#endif
#ifndef NDEBUG
fputs("Instruction 'HLT' (0x00) is not implemented.\n", stderr);
assert(0);
#else
abort();
#endif
#endif
