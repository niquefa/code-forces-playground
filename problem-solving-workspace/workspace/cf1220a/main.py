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


def get_count(string_number, m):
    min = 1000000
    for c in string_number:
        min = m[c] if m[c] < min else min
    return min


def main():
    I()
    s = S()
    m = Counter(s)
    ones = get_count("one", m)

    for c in "one":
        m[c] = 0 if c not in m else m[c] - ones
    zeroes = get_count("zero", m)

    ans = ""
    for _ in range(ones):
        ans += "1 "

    for _ in range(zeroes):
        ans += "0 "
    print("0" if ans == "" else ans.strip())


if __name__ == "__main__":
    main()
