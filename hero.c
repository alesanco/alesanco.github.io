#include <stdio.h>

#define SUCCESS 0
#define FAILURE 1

unsigned char s[] = {
  0x67, 0xbc, 0x41, 0xf6, 0x4e, 0xb2, 0xf2, 0xc5, 
  0xcb, 0xcb, 0xbe, 0xc3, 0xb4, 0xb6, 0xcb, 0xbb, 
  0x65, 0xac, 0x6a, 0x64, 0x16, 0x17, 0xa8, 0xa3, 
  0x6f, 0x64, 0xc9, 0xde, 0x9a, 0x6a, 0xaa, 0x60, 
  0xe7, 0x91, 0x5e, 0x54, 0xa2, 0xa0, 0x91, 0x73
};

int print_hero_message() {
  for (unsigned int m = 0; m < sizeof(s); ++m)
  {
    unsigned char c = s[m];
    c ^= m;
    c -= m;
    c ^= 0x40;
    c = ~c;
    c += 0xab;
    c ^= 0xdc;
    c = ~c;
    c ^= m;
    c = -c;
    c ^= m;
    c -= 0xa4;
    c = -c;
    c += 0x63;
    c = -c;
    c += m;
    s[m] = c;
  }

  printf("\n%s\n", s);

  return SUCCESS;
}