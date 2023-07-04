import sys

def MI(): return map(int, sys.stdin.readline().strip().split())
def LI(): return list(map(int, sys.stdin.readline().strip().split()))
def I(): return int(sys.stdin.readline().strip())

def solve():
    _, _ = MI()
    a = sum(LI())
    b = sum(LI())
    
    if a == b:
        print("Draw")
    elif a > b:
        print("Tsondu")
    else:
        print("Tenzing")

def main():
    test_count = I()
    for _ in range(test_count):
        solve()

if __name__ == "__main__":
    main()
