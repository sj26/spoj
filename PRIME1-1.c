#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Prime number sieve

// We keep a chain of witnessed composites

typedef struct composite_struct {
  int number;
  int *primes;
  int primes_len;
  struct composite_struct *next;
} composite;

composite *composites = NULL;

void witness(int number, int prime) {
  // Start with composites list
  composite **c;
  int l = 0;
  
  // Traverse until we find nothing, an insertion point, or the number
  for (c = &composites; (*c) && (*c)->number < number; c = &(*c)->next);
  
  // We already know about this composite, add another prime to it's list
  if (*c && (*c)->number == number) {
    (*c)->primes_len++;
    (*c)->primes = realloc((*c)->primes, sizeof(int) * (*c)->primes_len);
    (*c)->primes[(*c)->primes_len - 1] = prime;
    
  } else {
    // Construct a new composite struct with just this prime
    composite *c2 = (composite *)malloc(sizeof(composite));
    c2->number = number;
    c2->primes_len = 1;
    c2->primes = malloc(sizeof(int) * c2->primes_len);
    c2->primes[0] = prime;
    
    // We're inserting before a composite, or at the end
    if (*c) {
      c2->next = *c;
      *c = c2;
    // There is nothing! We are alone. *cue music*
    } else {
      c2->next = NULL;
      *c = c2;
    }
  }
}

static inline int witnessed(int candidate) {
  if (composites && composites->number == candidate) {
    for (int j = 0; j < composites->primes_len; j++) {
      witness(composites->number + composites->primes[j], composites->primes[j]);
    }
  
    composite *old = composites;
    composites = composites->next;
    free(old);
  
    return 1;
  }
  
  return 0;
}

int main(int argc, char** argv) {
  int cases;

  scanf("%d", &cases);
  
  for (int i = 0; i < cases; i++) {
    if (i > 0)
      printf("\n");
    
    int candidate_min, candidate_max;
    
    scanf("%d %d", &candidate_min, &candidate_max);
    
    for (int candidate = 2; candidate <= candidate_max; candidate++) {
      if (!witnessed(candidate)) {
        witness(candidate * candidate, candidate);
        
        if (candidate >= candidate_min) {
          printf("%d\n", candidate);
        }
      }
    }
  }
}
