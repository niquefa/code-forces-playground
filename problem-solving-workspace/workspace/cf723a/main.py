import sys
 
def LI(): return list(map(int, sys.stdin.readline().strip().split()))

def main():
    x = sorted(LI())
    print(x[2]-x[0])


if __name__ == "__main__":
    main()



