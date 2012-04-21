#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cases;

#define MAX 1000003

char c;

char number[MAX];
char number_reverse[MAX];
int number_len;
int number_len_half;

int main(int argc, char **argv) {
	scanf("%d\n", &cases);
	
	for (int i = 0; i < cases; i++) {
		number_len = number_len_half = 0;
		while ((c = getchar()) && c != '\n') {
			number[number_len++] = c;
			if (number_len % 2 == 0)
					number_len_half++;
		}
		number[number_len] = '\0';
		
		if (number_len == 1 && number[0] < '9') {
			printf("%c\n", number[0] + 1);
			
		} else if ((number_len == 1 && number[0] == '9') || (number_len == 2 && number[0] == '1' && number[1] == '0')) {
			printf("11\n");
			
		} else {
			for (int j = 0; j < number_len; j++)
				number_reverse[j] = number[number_len - j - 1];
			
			int reverse_cmp = memcmp(number + (number_len - number_len_half), number_reverse + (number_len - number_len_half), number_len_half);
			
			if (number_len % 2 == 1 && reverse_cmp == 0 && number[number_len_half] < '9') {
				number[number_len_half]++;
				printf("%s\n", number);
			
			} else if (number_len % 2 == 1 && reverse_cmp > 0 && number[number_len_half] < '9') {
				number[number_len_half]++;
				fwrite(number, 1, number_len_half + 1, stdout);
				fwrite(number_reverse + (number_len - number_len_half), 1, number_len_half, stdout);
				printf("\n");
				
			} else if (reverse_cmp < 0) {
				fwrite(number, 1, number_len_half, stdout);
				if (number_len % 2 == 1)
					printf("%c", number[number_len_half]);
				fwrite(number_reverse + (number_len - number_len_half), 1, number_len_half, stdout);
				printf("\n");
			
			} else {
				int remainder = 0;
				if (number[number_len_half - 1] < '9') {
					number[number_len_half - 1]++;
				} else {
					number[number_len_half - 1] = '0';
					remainder = 1;
					for (int j = (number_len_half - 2); j >= 0; j--) {
						if (remainder && number[j] == '9') {
							number[j] = '0';
						} else {
							number[j]++;
							remainder = 0;
							break;
						}
					}
				}
				
				if (remainder) {
					number[0] = '1';
					for (int i = 1; i < number_len; i++)
						number[i] = '0';
					number[number_len] = '1';
					fwrite(number, 1, number_len + 1, stdout);
				} else {
					fwrite(number, 1, number_len_half, stdout);
					if (number_len % 2 == 1)
						printf("0");
					for (int j = 0; j < number_len; j++)
						number_reverse[number_len - j - 1] = number[j];
					fwrite(number_reverse + (number_len - number_len_half), 1, number_len_half, stdout);
				}
				
				printf("\n");
			}
		} 
	}
}