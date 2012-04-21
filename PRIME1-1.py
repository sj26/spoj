import sys, math
cases = int(sys.stdin.readline().strip())
for case in range(1, cases + 1):
  candidate_min, candidate_max = map(int, sys.stdin.readline().strip().split())
  if candidate_min == 1:
    candidate_min = 3
  elif not candidate_min % 2:
    candidate_min += 1
  for candidate in range(candidate_min, candidate_max + 1, 2):
    if not candidate % 3:
      continue
    if any(not candidate % factor for factor in range(3, int(math.sqrt(candidate)), 2)):
      continue
    print(candidate)
  print() 

