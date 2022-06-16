import sys

def MI(): return map(int, sys.stdin.readline().strip().split())
def LI(): return list(map(int, sys.stdin.readline().strip().split()))

n, m = MI()
a = sorted(LI())
ans = 0
for i in range(m):
    if a[i] < 0 :
        ans -= a[i]

print(ans)