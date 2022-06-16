import sys

def LI(): return list(map(int, sys.stdin.readline().strip().split()))
def MI(): return map(int, sys.stdin.readline().strip().split())

def solve():
    n = int(input())
    laptop = []
    for i in range(n):
        a,b = MI()
        laptop.append((a,b))

    laptop.sort()

    alex = False
    #print(laptop)

    for i in range(len(laptop)-1):
        if laptop[i][1] > laptop[i+1][1] and laptop[i][0] < laptop[i+1][0]:
            alex = True
            break

    print("Happy Alex" if alex else "Poor Alex")

def main():
    solve()

if __name__ == "__main__":
    main()



