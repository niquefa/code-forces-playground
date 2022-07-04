import sys


def I():
    return int(sys.stdin.readline().strip())


def MI():
    return map(int, sys.stdin.readline().strip().split())


def LI():
    return list(map(int, sys.stdin.readline().strip().split()))


# just change the equation to a_j - j == a_i - i
def solve(n):
    a = LI()
    m = {}
    for i in range(len(a)):
        key = a[i] - i
        m[key] = m[key] + 1 if key in m else 1

    # print(m)
    ans = 0
    for key, value in m.items():
        ans += 0 if value < 2 else value * (value - 1) // 2
    print(ans)


def main():
    test_count = I()
    for _ in range(test_count):
        n = I()
        solve(n)


if __name__ == "__main__":
    main()
