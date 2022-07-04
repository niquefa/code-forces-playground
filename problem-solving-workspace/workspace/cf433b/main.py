import sys
import math


def MI():
    return map(int, sys.stdin.readline().strip().split())


def LI():
    return list(map(int, sys.stdin.readline().strip().split()))


def I():
    return int(sys.stdin.readline().strip())


def get_prefix_sum(a):
    s = [a[0]]
    for i in range(1, len(a)):
        s.append(a[i] + s[i - 1])
    return s


def main():
    n = I()
    v = LI()
    u = sorted(v)
    m = I()
    sv = get_prefix_sum(v)
    su = get_prefix_sum(u)
    for _ in range(m):
        t, l, r = MI()
        print(sv[r - 1] - sv[l - 1] + v[l - 1] if t == 1 else su[r - 1] - su[l - 1] + u[l - 1])


if __name__ == "__main__":
    main()
