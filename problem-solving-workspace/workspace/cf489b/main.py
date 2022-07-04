import sys


def LI():
    return list(map(int, sys.stdin.readline().strip().split()))


def solve():
    input()
    boys = sorted(LI())
    input()
    girls = sorted(LI())
    index_girls = 0
    ans = 0
    for boy in boys:
        for i in range(index_girls, len(girls)):
            if abs(boy - girls[i]) < 2:
                ans += 1
                girls[i] = 99999999
                break
    print(ans)


def main():
    solve()


if __name__ == "__main__":
    main()
