#cf1618a
import sys

def MI(): return map(int, sys.stdin.readline().strip().split())
def LI(): return list(map(int, sys.stdin.readline().strip().split()))
def I(): return int(sys.stdin.readline().strip())

def solve():
    b = LI()
    b.sort()
    print(str(b[0])+" "+str(b[1])+" "+str(b[6]-b[0]-b[1]))

def main():
    tests_count = I()
    for _ in range(tests_count):
        solve()
    
if __name__ == "__main__":
    main()


