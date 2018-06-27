#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE 1

struct bfi { char cmd; struct bfi *next, *jmp; };
struct mem { char val; struct mem *next, *prev; };

int brainfuck_interpreter(char filename[])
{
  FILE *ifd = fopen(filename, "r");
  int ch;
  struct bfi *p = 0, *n = 0, *j = 0, *pgm = 0;
  struct mem *m = calloc(1, sizeof*m);
  setbuf(stdout, NULL);

  while((ch = getc(ifd)) != EOF && (ifd != stdin || ch != '!' || j || !pgm)) {
    if (ch == '<' || ch == '>' || ch == '+' || ch == '-' ||
      ch == ',' || ch == '.' || ch == '[' || (ch == ']' && j)) {
      if ((n = calloc(1, sizeof*n)) == 0) return FAILURE;

      if (p) p->next = n; else pgm = n;

      n->cmd = ch; p = n;

      if (n->cmd == '[') { n->jmp=j; j = n; }
      else if (n->cmd == ']') { n->jmp = j; j = j->jmp; n->jmp->jmp = n; }
    }
  }
 
  while(j) { p = j; j = j->jmp; p->jmp = 0; p->cmd = ' '; }
 
  for (n = pgm; n; n = n->next)
    switch(n->cmd)
    {
      case '+': m->val++; break;
      case '-': m->val--; break;
      case '.': putchar(m->val); break;
      case ',': if((ch = getchar()) != EOF) m->val = ch; break;
      case '[': if (m->val == 0) n = n->jmp; break;
      case ']': if (m->val != 0) n = n->jmp; break;
      case '<':  if (!(m = m->prev)) return FAILURE; break;
      case '>':
        if (m->next == 0) {
          if ((m->next = calloc(1, sizeof*m)) == 0) return FAILURE;
          m->next->prev = m;
         }
        m = m->next;
        break;
    }
 
  return SUCCESS;
}