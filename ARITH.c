#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	int cases;
	
	char a[501];
	int a_len;
	char op;
	char b[501];
	int b_len;
	char ch;
	int max_len;
	char c[501];
	int c_len;
	int remainder;
	
	scanf("%d\n", &cases);
	
	for (int i = 0; i < cases; i++) {
		a_len = b_len = 0;
		
		while ((ch = getchar()) && isdigit(ch))
			a[a_len++] = ch;
		memset(a + a_len, 0, 501 - a_len);
		
		op = ch;
		
		while ((ch = getchar()) && isdigit(ch))
			b[b_len++] = ch;
		memset(b + b_len, 0, 501 - b_len);
		
		assert(ch == '\n');
		
		if (a_len >= b_len)
			max_len = a_len;
		else
			max_len = b_len;
		
		memset(c, 0, 501);
		
		c_len = max_len;
		remainder = 0;
		for (int i = 0; i < max_len; i++) {
			int a_int = (long)(a[i] - '0'),
				b_int = (long)(b[i] - '0'),
				c_int;
			
			if (op == '+') {
				c_int = (long)(a_int + b_int + remainder);
			} else if (op == '-') {
				c_int = (long)(a_int - b_int - remainder);
			} else if (op == '*') {
				c_int = (long)(a_int * b_int + remainder);
			}
			
			remainder = c_int / 10;
			c_int = c_int % 10;
			
			c[c_len - i - 1] = '0' + (char)(c_int);
		}
		if (remainder) {
			memmove(c + 1, c, c_len);
			c[0] = '0' + (char)(remainder);
			max_len = ++c_len;
		}

		for (int i = 0; i < (max_len - a_len + 1); i++)
			printf(" ");
		printf("%s\n", a);
		
		printf("%c", op);
		
		for (int i = 0; i < (max_len - b_len); i++)
			printf(" ");
		printf("%s\n", b);
		
		for (int i = 0; i < (max_len + 1); i++)
			printf("-");
		printf("\n");
		
		for (int i = 0; i < (max_len - c_len + 1); i++)
			printf(" ");
		printf("%s\n\n", c);
	}
}
