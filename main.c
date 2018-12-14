#include "tinyprintf.h"


int main()
{
  // printf("%-05d\n", 42);
  printf_("%05d", 42);
  return 0;
}

// internal _putchar wrapper
static inline void _out_char(char character, void* buffer, size_t idx, size_t maxlen)
{
  (void)buffer; (void)idx; (void)maxlen;
  if (character) {
    _putchar(character);
  }
}