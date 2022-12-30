import sys
t = int(sys.stdin.readline().strip())
for _ in range(t):
  x, y, n = map(int, sys.stdin.readline().strip().split())
  if n % x == y :
    print(n)
  elif n % x > y :
    print(n-((n%x)-y))
  else :
    print(n - (n%x) - (x-y))