s, n = map(int, input().split())
list = [(int, int)] * n
for i in range(n):
    x, y = map(int, input().split())
    list[i] = (x, y)

sorted_list = list.sort()

ans = True

for item in list:
    if item[0] >= s:
        ans = False
        break
    s += item[1]

print("YES" if ans else "NO")
