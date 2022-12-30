import sys
for _ in range(int(sys.stdin.readline().strip())):
  a, b, c, d = map(int, sys.stdin.readline().strip().split())
  ans = 0
  if b > a :
    ans += 1
  if c > a :
    ans += 1
  if d > a :
    ans += 1
  print(ans)