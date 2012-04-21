import sys

def is_palindrome(number):
  number = str(number)
  print(number[:len(number)//2], number[:len(number)//2 - 1:-1])
  return number[:len(number)//2] == number[:len(number)//2 - 1:-1]

def next_palindrome(number):
  number = int(number)
  while not is_palindrome(number):
    number += 1
  return number

cases = int(sys.stdin.readline().strip())
for number in map(lambda s: s.strip(), sys.stdin):
  print(next_palindrome(number))