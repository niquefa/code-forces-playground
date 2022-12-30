import sys
a = list(map(int, sys.stdin.readline().strip().split()))
s = list(sys.stdin.readline().strip())
ans = 0
for i in s:
  ans += a[int(i)-1]
print(ans)
