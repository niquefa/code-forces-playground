import sys
t = int(sys.stdin.readline().strip())
for _ in range(t):
  a, b = map(int, sys.stdin.readline().strip().split())
  s = min(max(a+a,b+b), max(2*a,b), max(2*b,a))
  print(s*s)
  