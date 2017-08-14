#include "utils.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>

char *read_file(const char *fn, size_t *size_out) {
  if (!fn) {
    errno = EINVAL;
    return NULL;
  }
  FILE *fp = fopen(fn, "rb");
  if (!fp)
    return NULL;
  if (fseek(fp, 0, SEEK_END) != 0) {
    fclose(fp);
    return NULL;
  }
  long size = ftell(fp);
  if (size < 0) {
    fclose(fp);
    return NULL;
  }
  if (fseek(fp, 0, SEEK_SET) != 0) {
    fclose(fp);
    return NULL;
  }
  char *buf = malloc(size);
  if (!buf) {
    fclose(fp);
    return NULL;
  }
  size_t len_read = fread(buf, 1, size, fp);
  if (len_read != (size_t)size) {
    fclose(fp);
    free(buf);
    return NULL;
  }
  fclose(fp);
  if (size_out)
    *size_out = len_read;
  return buf;
}
