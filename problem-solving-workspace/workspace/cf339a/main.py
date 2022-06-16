import sys

def S(): return sys.stdin.readline().strip()

a = S().split("+")
a.sort()

for i in range(len(a)):
    if i > 0 :
        print("+", end = "")
    print(a[i], end = "")
print()