#include <stdio.h>
#include <string.h>

char b64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void decodeblock(unsigned char in[], char *text) {
  unsigned char out[4];
  out[0] = in[0] << 2 | in[1] >> 4;
  out[1] = in[1] << 4 | in[2] >> 2;
  out[2] = in[2] << 6 | in[3] >> 0;
  out[3] = '\0';
  strncat(text, out, sizeof(out));
}

void base64_decode(char *base64, char *text) {
  int c, phase, i;
  unsigned char in[4];
  char *p;

  text[0] = '\0';
  phase = 0; i = 0;

  while(base64[i]) {
    c = (int) base64[i];
    if (c == '=') {
      decodeblock(in, text); 
      break;
    }

    p = strchr(b64, c);

    if (p) {
      in[phase] = p - b64;
      phase = (phase + 1) % 4;
      if(phase == 0) {
        decodeblock(in, text);
        in[0] = in[1] = in[2] = in[3] = 0;
      }
    }

    i++;
  }
}

void encodeblock(unsigned char in[], char base64[], int len) {
    unsigned char out[5];
    out[0] = b64[ in[0] >> 2 ];
    out[1] = b64[ ((in[0] & 0x03) << 4) | ((in[1] & 0xf0) >> 4) ];
    out[2] = (unsigned char) (len > 1 ? b64[ ((in[1] & 0x0f) << 2) | ((in[2] & 0xc0) >> 6) ] : '=');
    out[3] = (unsigned char) (len > 2 ? b64[ in[2] & 0x3f ] : '=');
    out[4] = '\0';
    strncat(base64, out, sizeof(out));
}

void base64_encode(char *text, char *base64) {
  unsigned char in[3];
  int i, len = 0;
  int j = 0;

  base64[0] = '\0';
  while(text[j]) {
    len = 0;
    for (i = 0; i < 3; i++) {
     in[i] = (unsigned char) text[j];
     if (text[j]) {
        len++; j++;
      }
      else in[i] = 0;
    }
    if (len) encodeblock(in, base64, len);
  }
}