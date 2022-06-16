import sys
from collections import Counter
def LI(): return list(map(int, sys.stdin.readline().strip().split()))

def solve(a):
    if len(a) == 1:
        print("0")
        return

    m = Counter(a)

    if len(m.keys()) == 1:
        print("1")
        return

    pairs = []
    for i in m.keys():
        if m[i] > 1 :
            pairs.append((m[i],i))

    pairs.sort(reverse=True)
    answer = len(a)//2

    if len(pairs) == 0 :
        print("1")
        return

    while answer > 0:
        most_frequent_left = pairs[0][0]-answer
        if most_frequent_left < 0 :
             answer -= 1
             continue
        different_numbers_left = len(m.keys())-1
        if most_frequent_left > 0 :
            different_numbers_left += 1
        if different_numbers_left >= answer :
            break
        answer -= 1
    
    print(answer)

def main():
    t = int(input())
    for i in range(t):
        int(input())
        a = LI()
        solve(a)

if __name__ == "__main__":
    main()
