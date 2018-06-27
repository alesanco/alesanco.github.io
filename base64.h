#ifndef BASE64_H_INCLUDED
#define BASE64_H_INCLUDED

/* Prototypes for the functions */
void base64_encode(char *plain_text, char *base64);
void base64_decode(char *base64, char *plain_text);

#endif