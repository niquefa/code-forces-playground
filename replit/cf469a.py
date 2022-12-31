import sys
n, m = map(int, sys.stdin.readline().strip().split())
day = 0
while True:
  if n == 0 :
    break
  day += 1
  n -= 1
  if day % m == 0 :
    n += 1
print(day)