import sys


def MI():
    return map(int, sys.stdin.readline().strip().split())


def LI():
    return list(map(int, sys.stdin.readline().strip().split()))


def main():
    n, m = MI()
    l = LI()
    s = set()
    sum_from_index = [0] * n
    for i in range(n):
        index = n - 1 - i
        s.add(l[index])
        sum_from_index[index] = len(s)
    for i in range(m):
        q = int(input())
        print(sum_from_index[q - 1])
    print(sum_from_index)


if __name__ == "__main__":
    main()
