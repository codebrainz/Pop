#include "ops.h"

#ifdef __GNUC__
#define POP_COMPUTED_GOTO 1
#endif

#include "utils.h"

#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#ifndef NDEBUG
#include <assert.h>
#else
#include <stdlib.h>
#endif

int main(int argc, char **argv) {

  if (argc < 2) {
    fputs("error: missing bytecode file argument\n", stderr);
    return 1;
  }

  register int pc = 0;
  register op_t op = 0;
  size_t code_len = 0;
  char *code = read_file(argv[1], &code_len);

  if (!code) {
    fprintf(stderr, "error: unable to open bytecode file '%s': %s\n", argv[1],
            strerror(errno));
    return 1;
  }

#include "decode.c"

  free(code);

  return 0;
}
