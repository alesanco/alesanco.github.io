#include <stdio.h>

#define SUCCESS 0
#define FAILURE 1

unsigned char asciititle_text[] = {
    0x20, 0x20, 0x20, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x20, 0x20, 0x2e, 0x5f,
    0x5f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0d, 0x0a,
    0x20, 0x20, 0x2f, 0x20, 0x20, 0x5f, 0x20, 0x20, 0x5c, 0x20, 0x7c, 0x20,
    0x20, 0x7c, 0x20, 0x20, 0x20, 0x5f, 0x5f, 0x5f, 0x5f, 0x20, 0x20, 0x20,
    0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x20,
    0x20, 0x20, 0x20, 0x5f, 0x5f, 0x5f, 0x5f, 0x20, 0x20, 0x20, 0x5f, 0x5f,
    0x5f, 0x5f, 0x20, 0x20, 0x5f, 0x5f, 0x5f, 0x5f, 0x20, 0x20, 0x0d, 0x0a,
    0x20, 0x2f, 0x20, 0x20, 0x2f, 0x5f, 0x5c, 0x20, 0x20, 0x5c, 0x7c, 0x20,
    0x20, 0x7c, 0x20, 0x5f, 0x2f, 0x20, 0x5f, 0x5f, 0x20, 0x5c, 0x20, 0x2f,
    0x20, 0x20, 0x5f, 0x5f, 0x5f, 0x2f, 0x5c, 0x5f, 0x5f, 0x20, 0x20, 0x5c,
    0x20, 0x20, 0x2f, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x5f, 0x2f, 0x20, 0x5f,
    0x5f, 0x5f, 0x5c, 0x2f, 0x20, 0x20, 0x5f, 0x20, 0x5c, 0x20, 0x0d, 0x0a,
    0x2f, 0x20, 0x20, 0x20, 0x20, 0x7c, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x20,
    0x20, 0x7c, 0x5f, 0x5c, 0x20, 0x20, 0x5f, 0x5f, 0x5f, 0x2f, 0x20, 0x5c,
    0x5f, 0x5f, 0x5f, 0x20, 0x5c, 0x20, 0x20, 0x2f, 0x20, 0x5f, 0x5f, 0x20,
    0x5c, 0x7c, 0x20, 0x20, 0x20, 0x7c, 0x20, 0x20, 0x5c, 0x20, 0x20, 0x5c,
    0x5f, 0x5f, 0x28, 0x20, 0x20, 0x3c, 0x5f, 0x3e, 0x20, 0x29, 0x0d, 0x0a,
    0x5c, 0x5f, 0x5f, 0x5f, 0x5f, 0x7c, 0x5f, 0x5f, 0x20, 0x20, 0x2f, 0x5f,
    0x5f, 0x5f, 0x5f, 0x2f, 0x5c, 0x5f, 0x5f, 0x5f, 0x20, 0x20, 0x3e, 0x5f,
    0x5f, 0x5f, 0x5f, 0x20, 0x20, 0x3e, 0x28, 0x5f, 0x5f, 0x5f, 0x5f, 0x20,
    0x20, 0x2f, 0x5f, 0x5f, 0x5f, 0x7c, 0x20, 0x20, 0x2f, 0x5c, 0x5f, 0x5f,
    0x5f, 0x20, 0x20, 0x3e, 0x5f, 0x5f, 0x5f, 0x5f, 0x2f, 0x20, 0x0d, 0x0a,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x2f, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x2f, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x5c, 0x2f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5c,
    0x2f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x2f, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x5c, 0x2f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20};
unsigned int asciititle_text_len = 358;

int print_ascii_title()
{
  printf("%s\n", asciititle_text);
  return SUCCESS;
}