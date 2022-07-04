# cf1626a
import sys
from collections import Counter


def MI():
    return map(int, sys.stdin.readline().strip().split())


def LI():
    return list(map(int, sys.stdin.readline().strip().split()))


def I():
    return int(sys.stdin.readline().strip())


def S():
    return sys.stdin.readline().strip()


def solve():
    n, current_ram = MI()
    a = LI()
    b = LI()
    v = []
    for i in range(n):
        v.append((a[i], b[i]))

    v.sort()

    for i in range(n):
        if v[i][0] > current_ram:
            break
        current_ram += v[i][1]

    print(current_ram)


def main():
    tests_count = I()
    for _ in range(tests_count):
        solve()


if __name__ == "__main__":
    main()
