import sys


def MI():
    return map(int, sys.stdin.readline().strip().split())


def LI():
    return list(map(int, sys.stdin.readline().strip().split()))


def find_first_down(a):
    for i in range(len(a) - 1):
        if a[i] > a[i + 1]:
            return i
    return -1


def find_second_up(a, index_from):
    for i in range(index_from, len(a) - 1):
        if a[i] < a[i + 1]:
            return i
    return -1


def solve(a):
    index_first_down = find_first_down(a)
    if index_first_down < 0:
        print("yes\n1 1")
        return
    s = sorted(a)

    index_second_up = find_second_up(a, index_first_down)
    if index_second_up < 0:
        print("no")
        return

    c = a.copy()
    going_up = index_first_down
    going_down = index_second_up
    for i in range(index_second_up - index_first_down + 1):
        c[going_up] = a[going_down]
        going_up += 1
        going_down -= 1

    if c == s:
        print("yes\n" + str(index_first_down) + " " + str(index_second_up))
    else:
        print("no")


def main():
    n = int(input())
    a = [0] + LI() + [10e9 + 1]
    solve(a)


if __name__ == "__main__":
    main()
