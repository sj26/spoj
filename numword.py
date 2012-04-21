# Some of the most obtuse python I've ever written -- that's saying something!
import sys
def a(b):
 if not b: return 'zero'
 c=[]
 for d,e,f in((1000000000,1000,'billion'),(1000000,1000,'million'),(1000,1000,'thousand'),(100,10,'hundred')):
  g=b//d%e
  if g:c+=[a(g),f]
 h=(b//10)%10
 i=b%10
 if h==1:
  c+=[('ten','eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','nineteen')[i]]
 else:
  if h:c+=[('twenty','thirty','fourty','fifty','sixty','seventy','eighty','ninety')[h-2]]
  if i:c+=[('one','two','three','four','five','six','seven','eight','nine')[i-1]]
 return' '.join(c)
sys.stdin.readline()
for b in map(int,map(lambda s:s.strip(),sys.stdin)):
  print(a(b))