import sys

def MI(): return map(int, sys.stdin.readline().strip().split())
def LI(): return list(map(int, sys.stdin.readline().strip().split()))

def solve():
    n, k = MI()
    a = sorted(LI())
    b = sorted(LI(), reverse=True)
    plus = 0
    for i in range(k):
        plus += max(b[i]-a[i], 0)
    print(str(sum(a)+plus))

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()



