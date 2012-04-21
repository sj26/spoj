#include <stdio.h>
#include <string.h>

const int MAX = 1000000000, LMT = 31622;
int flag[15625000]; // MAX<<6

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() {
    int i, j, k;
    for(i = 3; i < LMT; i += 2)
        if(!ifc(i))
            for(j = i*i, k = i<<1; j < MAX; j += k)
                isc(j);
}

int main() {
  sieve();
  
  int cases;
  scanf("%d", &cases);
  
  for (int i = 0; i < cases; i++) {
    int min, max;
    scanf("%d %d", &min, &max);
    
    if (min < 3) {
      printf("2\n");
      min = 3;
    } else if (min % 2 == 0) {
      min++;
    }
    
    for (int c = min; c <= max; c += 2) {
      if (!ifc(c)) {
        printf("%d\n", c);
      }
    }
    
    printf("\n");
  }
}