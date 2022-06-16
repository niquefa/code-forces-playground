import sys
 
def LI(): return list(map(int, sys.stdin.readline().strip().split()))

def main():
    k = int(input())
    a = sorted(LI(), reverse=True)
    ans = 0
    accum = 0
    for x in a:
        if accum >= k:
            break
        ans += 1
        accum += x
    
    print("-1" if accum < k else str(ans))

if __name__ == "__main__":
    main()
