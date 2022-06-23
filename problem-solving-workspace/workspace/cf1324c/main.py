import sys
import re

def I(): return int(sys.stdin.readline().strip())
def S(): return sys.stdin.readline().strip()

def solve():
    s = S()
    onlyR = True
    onlyL = True
    for ch in s:
        onlyR &= ch == 'R'
        onlyL &= ch == 'L'
        if not onlyR and not onlyL:
            break
    if onlyR:
        print('1')
        return 
    if onlyL:
        print(len(s)+1)
        return

    a = re.split("[R]+",s)
    #print(a)
    ans = 0
    
    for token in a:
        ans = ans if token == '' or len(token)+1 < ans else len(token)+1
    print(ans)

def main():
    test_count = I()
    for _ in range(test_count):
        solve()

if __name__ == "__main__":
    main()
