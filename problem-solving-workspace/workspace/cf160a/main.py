import sys
def LI(): return list(map(int, sys.stdin.readline().strip().split()))
input()
c = LI()
c.sort(reverse=True)
s = sum(c)
a = 0
for i in range(len(c)):
    a += c[i]
    if a > s//2 :
        print(str(i+1))
        break