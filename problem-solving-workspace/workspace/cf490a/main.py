import sys


def MI():
    return map(int, sys.stdin.readline().strip().split())


def LI():
    return list(map(int, sys.stdin.readline().strip().split()))


def main():
    m = [[] for j in range(4)]
    _ = MI()
    t = LI()
    for i in range(len(t)):
        m[t[i]].append(i + 1)
    ia = ib = ic = 0
    ans = []

    while ia < len(m[1]) and ib < len(m[2]) and ic < len(m[3]):
        ans.append([str(m[1][ia]), str(m[2][ib]), str(m[3][ic])])
        ia += 1
        ib += 1
        ic += 1
    print(len(ans))
    for item in ans:
        print(" ".join(item))


if __name__ == "__main__":
    main()
