import sys

def MI(): return map(int, sys.stdin.readline().strip().split())
def LI(): return list(map(int, sys.stdin.readline().strip().split()))
def I(): return int(sys.stdin.readline().strip())

def solve():
    _, x = MI()
    a = LI() + LI() + LI()
    k = 0
    #print(a)
    for y in a:
        if (y|x) != x:
            continue
        if k == x:
            print("Yes")
            return
        k |= y
    print("No")


def main():
    test_count = I()
    for _ in range(test_count):
        solve()

if __name__ == "__main__":
    main()
#python3 hello.py < t.in