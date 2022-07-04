import sys
import math


def MI():
    return map(int, sys.stdin.readline().strip().split())


def LI():
    return list(map(int, sys.stdin.readline().strip().split()))


def I():
    return int(sys.stdin.readline().strip())


def solve():
    n = I()
    a = LI()
    ans = 0
    for i in range(n):
        for j in range(i + 1, n):
            ans += 1 if math.gcd(a[i], 2 * a[j]) > 1 or math.gcd(a[j], 2 * a[i]) > 1 else 0
    print(ans)


def main():
    test_count = I()
    for _ in range(test_count):
        solve()


if __name__ == "__main__":
    main()
