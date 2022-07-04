# cf1626a
import sys
from collections import Counter


def I():
    return int(sys.stdin.readline().strip())


def S():
    return sys.stdin.readline().strip()


def solve():
    s = S()
    s = "".join(sorted(list(s)))
    print(s)


def main():
    tests_count = I()
    for _ in range(tests_count):
        solve()


if __name__ == "__main__":
    main()
