import sys
for _ in range(int(sys.stdin.readline().strip())):
  n = int(sys.stdin.readline().strip())
  a = list(map(int, sys.stdin.readline().strip().split()))
  b = list(map(int, sys.stdin.readline().strip().split()))
  min_a = min(a)
  min_b = min(b)
  ans = 0
  for i in range(n):
    ans += max( a[i] - min_a, b[i] - min_b )
  print(ans)