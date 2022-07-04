import sys


def MI():
    return map(int, sys.stdin.readline().strip().split())


def LI():
    return list(map(int, sys.stdin.readline().strip().split()))


n, l = MI()

a = LI()

a = sorted(a)
first_gap = a[0]
last_gap = l - a[len(a) - 1]

a.append(0)
a.append(l)

a = sorted(a)

d = []
for i in range(len(a) - 1):
    d.append(a[i + 1] - a[i])

d = sorted(d)

x = [d[len(d) - 1] / 2, first_gap, last_gap]
print(max(x))
