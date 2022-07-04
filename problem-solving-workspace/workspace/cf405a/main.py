import sys


def LI():
    return list(map(int, sys.stdin.readline().strip().split()))


cols = int(input())
boxes_in_col = LI()
rows = max(boxes_in_col)
m = [[0 for i in range(cols)] for j in range(rows)]

for c in range(cols):
    for r in range(boxes_in_col[c]):
        m[rows - 1 - r][c] = 1

sum_by_row = []

for r in range(rows):
    sum_by_row.append(sum(m[r]))


g = [[0 for i in range(cols)] for j in range(rows)]

for r in range(rows):
    col_index = cols - 1
    for c in range(sum_by_row[r]):
        g[r][cols - 1 - c] = 1

for c in range(cols):
    accum = 0
    for r in range(rows):
        accum += g[r][c]
    if c > 0:
        print(" ", end="")
    print(accum, end="")
print()
