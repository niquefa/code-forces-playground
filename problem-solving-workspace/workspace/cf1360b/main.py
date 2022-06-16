import sys

def LI(): return list(map(int, sys.stdin.readline().strip().split()))

def solve():
    n = int(input())
    s = sorted(LI())
    d = []
    for i in range(n-1):
        d.append(s[i+1] - s[i])
    print(min(d))

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()



