import sys

def MI(): return map(int, sys.stdin.readline().strip().split())
def I(): return int(sys.stdin.readline().strip())

def main():
    n, m, k = MI()
    a = m*[0]
    for i in range(m):
        a[i] = I()
    f = I()

    ans = 0

    for x in a:
        if bin( f ^ x ).count("1") <= k:
            ans += 1
    print(ans)


if __name__ == "__main__":
    main()
