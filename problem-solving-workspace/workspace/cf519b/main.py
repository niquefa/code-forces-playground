import sys


def MI():
    return map(int, sys.stdin.readline().strip().split())


def LI():
    return list(map(int, sys.stdin.readline().strip().split()))


def solve(a, b):
    for i in range(len(b)):
        if a[i] != b[i]:
            print(a[i])
            return


def main():
    n = int(input())
    a = [-1] + sorted(LI()) + [10e10]
    b = [-1] + sorted(LI()) + [10e10]
    c = [-1] + sorted(LI()) + [10e10]
    solve(a, b)
    solve(b, c)


if __name__ == "__main__":
    main()
