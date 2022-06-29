
#cf1669b
import sys
from collections import Counter

def MI(): return map(int, sys.stdin.readline().strip().split())
def LI(): return list(map(int, sys.stdin.readline().strip().split()))
def I(): return int(sys.stdin.readline().strip())

def solve():
    n = I()
    a = LI()
    m = {}
    for x in a:
        if x not in m:
            m[x] = 0
        m[x] += 1
        if m[x] == 3:
            print(x)
            return
    print(-1)


    #Gives time limit exceeded:
    #dict = Counter(a)
    #dict_reverse_sorted_by_value = {k: v for k, v in sorted(dict.items(), key=lambda item: item[1], reverse=True)}
    #first_key = next(iter(dict_reverse_sorted_by_value.items()))[0]
    #first_value = next(iter(dict_reverse_sorted_by_value.items()))[1]
    #print(first_key if first_value >= 3 else -1)

def main():
    tests_count = I()
    for _ in range(tests_count):
        solve()
    
if __name__ == "__main__":
    main()


