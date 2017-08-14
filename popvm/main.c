#include "ops.h"

#ifdef __GNUC__
#define POP_COMPUTED_GOTO 1
#endif

#ifndef NDEBUG
#include <assert.h>
#include <stdio.h>
#else
#include <stdlib.h>
#endif

int main() {
  static const char code[] = { 0 };
  register int pc = 0;
#include "decode.c"
  return 0;
}
