import sys

def LI(): return list(map(int, sys.stdin.readline().strip().split()))
def MI(): return map(int, sys.stdin.readline().strip().split())

# def solve(a):
    
#     even_count = 0
#     odd_count = 0
#     for i in range(len(a)):
#         even_count += 1 if a[i]%2 == 0 else 0
#         odd_count += 1 if a[i]%2 == 1 else 0
    
#     if even_count%2 != odd_count%2:
#         print("NO")
#         return

#     i = 0
#     matched = [False]*len(a)
#     while i + 1 < len(a):
#         if a[i] - a[i+1] == -1:
#             matched[i] = matched[i+1] = True
#         i += 2

#     even_count = 0
#     odd_count = 0
#     for i in range(len(a)):
#         even_count += 1 if not matched[i] and a[i]%2 == 0 else 0
#         odd_count += 1 if not matched[i] and a[i]%2 == 1 else 0

#     print("YES" if even_count%2 == 0 and odd_count%2 == 0 else "NO")

# def main():
#     t = int(input())
#     for i in range(t):
#         n = int(input())
#         a = sorted(LI())
#         solve(a)

# if __name__ == "__main__":
#     main()


t = int(input())
for tt in range(t):
    n = int(input())
    a = LI()
    c = sum(i % 2 for i in a)
    if c % 2 == 1:
        b = [i + 1 for i in a]
        # print(str(a))
        # print(str(b))
        # print(set(a) & set(b))
        # print(bool(set(a) & set(b)))

        if set(a) & set(b):
            print("YES")
            # print("+++++")
        else:
            print ("NO")
    else:
        print ("YES")
