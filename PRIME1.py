import sys, collections
cases = int(sys.stdin.readline().strip())
for case in range(1, cases + 1):
  candidate_min, candidate_max = map(int, sys.stdin.readline().strip().split())
  # Python is good at sparse dictionaries, so we'll use a bubbling
  # Sieve of Erastothenes to be memory efficient and fairly
  # computationally efficient
  composites = collections.defaultdict(list)
  for candidate in range(2, candidate_max + 1):
    if candidate in composites:
      # This candidate is a composite.
      # Find the next multiple of each prime which found this composite.
      for prime in composites[candidate]:
        composites[prime + candidate].append(prime)
      # We don't care about this copmosite any more.
      del composites[candidate]
    else:
      # This candidate is prime!
      # Print it if we should
      if candidate >= candidate_min:
        print(candidate)
      # Find the first composite of this prime.
      composites[candidate * candidate] = [candidate]
  print()

