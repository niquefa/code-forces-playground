import sys
t = int(sys.stdin.readline().strip())
for _ in range(t):
  n = int(sys.stdin.readline().strip())
  print( "NO" if n&(n-1) == 0 else "YES")