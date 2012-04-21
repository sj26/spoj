#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char ops[] = { '+', '-', '*', '/', '^' };
const char letters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
  'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
  'z' };

int cases;
char c;
char stack[400][401];
int stack_len[400];
int l;

#define offset(of, in) ((char *)memchr((void *)(&in), of, sizeof(in)) - (char *)(&in))

static void print_stack() {
  while (stack_len[l]) {
    printf("%c", stack[l][--stack_len[l]]);
    stack[l][stack_len[l]] = '\0';
  }
}

int main(int argc, char **argv) {
  void *op;
  short p, sp;

  l = 0;
  memset(stack_len, 0, 400 * sizeof(int));
  memset(stack, 0, 400 * 401 * sizeof(char));

  scanf("%d\n", &cases);
  
  for (int i = 0; i < cases; i++) {
    while (!feof(stdin) && (c = fgetc(stdin)) && c != '\n') {
      if (c == '(') {
        l++;
      } else if (c == ')') {
        print_stack();
        l--;
      } else if (memchr(&ops, c, sizeof(ops))) {
        p = offset(c, ops);
        while (stack_len[l] > 0 && offset(stack[l][stack_len[l] - 1], ops) > p) {
          printf("%c", stack[l][stack_len[l] - 1]);
          stack[l][--stack_len[l] - 1] = 0;
        }
        stack[l][stack_len[l]++] = c;
      } else if (memchr(&letters, c, sizeof(letters))) {
        printf("%c", c);
      } else {
        exit(-1);
      }
    }
    print_stack();
    printf("\n");
  }
}
