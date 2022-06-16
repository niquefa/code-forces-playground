import sys
 
def LI(): return list(map(int, sys.stdin.readline().strip().split()))

def main():
    int(input())
    b = sorted(LI())
    s = set(b)
    if len(s) == 1:
        if len(b) == 2:
            print("0 1")
        else:
            print("0 "+str(len(b)*(len(b)-1)//2))
    else:
        print(str(b[len(b)-1]-b[0])+" "+str(b.count(b[0]) * b.count(b[len(b)-1])) )

if __name__ == "__main__":
    main()
