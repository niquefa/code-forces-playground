import sys
n, t = map(int, sys.stdin.readline().strip().split())
a = [0] + list(map(int, sys.stdin.readline().strip().split()))
arrived = False
current_cell = 1
while True:
  current_cell = current_cell + a[current_cell]
  if current_cell == t :
    arrived = True
    break
  if current_cell == n :
    break

print( "YES" if arrived else "NO")