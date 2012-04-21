#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv) {
  int cases;  
  
  long number;
  char number_s[1000000];
  int number_len;
  int number_len_half;
  char number_s_left[500000];
  long number_left;
  char number_s_middle;
  int number_middle;
  char number_s_right[500000];
  long number_right;
  
  char number_s_left_reversed[4];
  long number_left_reversed;
  
  scanf("%d\n", &cases);
  
  for (int i = 0; i < cases; i++) {
    scanf("%ld\n", &number); 
    
    sprintf(number_s, "%ld", number);
    
    number_len = strlen(number_s);
    number_len_half = floor(number_len / 2);
    
    memcpy(&number_s_left, &number_s, number_len_half);
    number_s_left[number_len_half] = '\0';
    number_left = atoi(number_s_left);
    
    if (number_len_half * 2 < number_len) {
      number_s_middle = number_s[number_len_half];
      number_middle = number_s_middle - '0';
    } else {
      number_s_middle = '\0';
    }
    
    memcpy(&number_s_right, &(number_s[number_len - number_len_half]), number_len_half);
    number_s_right[number_len_half] = '\0';
    number_right = atoi(number_s_right);
    
    for (int j = 0; j < number_len_half; j++)
      number_s_left_reversed[j] = number_s_left[number_len_half - j - 1];
    number_s_left_reversed[number_len_half] = '\0';
    number_left_reversed = atoi(number_s_left_reversed);
    
    if (number_s_left[0] == '\0' && number_s_right[0] == '\0') {
      number_middle++;
      if (number_middle == 10) {
        number_middle = 11;
      }
    } else if (number_left_reversed > number_right) {
      number_right = number_left_reversed;
    } else if (number_s_middle != '\0' && number_middle < 9) {
      number_middle++;
      number_right = number_left_reversed;
    } else {
      number_left++;
      sprintf(number_s_left, "%ld", number_left);

      if (number_s_middle != '\0')
        number_middle = 0;
      
      int l = strlen(number_s_left);
      for (int j = 0; j < l; j++)
        number_s_left_reversed[j] = number_s_left[l - j - 1];
      number_s_left_reversed[l] = '\0';
      number_left_reversed = atoi(number_s_left_reversed);
      
      number_right = number_left_reversed;
    }

    if (number_s_left[0] != '\0')
      printf("%ld", number_left);
    if (number_s_middle != '\0')
      printf("%d", number_middle);
    if (number_s_right[0] != '\0')
      printf("%ld", number_right);
    printf("\n");
  }
}