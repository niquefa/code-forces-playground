import sys
 
def MI(): return map(int, sys.stdin.readline().strip().split())
def LI(): return list(map(int, sys.stdin.readline().strip().split()))

def solve(n,l):
    l = sorted(l)
    for i in range(len(l)-1) :
        if l[i+1] - l[i] > 1 :
            return False
    return True

def main():
    t = int(input())
    for i in range(t):
        n = MI()
        l = LI()
        print("YES" if solve(n,l) else "NO")

if __name__ == "__main__":
    main()



