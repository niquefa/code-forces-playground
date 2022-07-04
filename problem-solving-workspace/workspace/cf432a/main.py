import sys


def MI():
    return map(int, sys.stdin.readline().strip().split())


def LI():
    return list(map(int, sys.stdin.readline().strip().split()))


def main():
    _, k = MI()
    l = sorted(LI())
    i = 0
    ans = 0
    while True:
        if i + 2 >= len(l):
            break
        if 5 - l[i] >= k and 5 - l[i + 1] >= k and 5 - l[i + 2] >= k:
            ans += 1
        i += 3
    print(ans)


if __name__ == "__main__":
    main()
