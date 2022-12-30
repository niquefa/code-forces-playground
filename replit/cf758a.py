import sys
n = int(sys.stdin.readline().strip())
a = list(map(int, sys.stdin.readline().strip().split()))
m = max(a)
ans = sum(m-x for x in a)
print(ans)