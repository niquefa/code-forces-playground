import sys


def MI():
    return map(int, sys.stdin.readline().strip().split())


def LI():
    return list(map(int, sys.stdin.readline().strip().split()))


def I():
    return int(sys.stdin.readline().strip())


def solve():
    n = I()
    a = LI()
    a.sort()
    sum = [a[0]]
    for i in range(1, n):
        sum.append(sum[i - 1] + a[i])

    best = sum[0] + (sum[n - 1] - sum[0]) / (n - 1)
    for i in range(1, n - 1):
        x = sum[i] / (i + 1)
        y = (sum[n - 1] - sum[i]) / (n - 1 - i)
        best = x + y if x + y > best else best

    print(best)


def main():
    t = I()
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
