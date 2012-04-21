import sys
from string import ascii_letters as letters
ops = ('+', '-', '*', '/', '^')
cases = int(sys.stdin.readline().strip())
for line in sys.stdin:
  stack = [[]]
  for c in line.strip():
    if c == '(':
      stack.append([])
    elif c == ')':
      print(''.join(stack.pop()), end="")
    elif c in ops:
      i = ops.index(c)
      while stack and stack[-1] and ops.index(stack[-1][-1]) > i:
        print(stack[-1].pop(), end="")
      stack[-1].append(c)
    elif c in letters:
      print(c, end="")
  print(''.join(map(''.join, reversed(stack))))
