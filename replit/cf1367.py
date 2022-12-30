import sys
t = int(sys.stdin.readline().strip())
for _ in range(t):
  n = int(sys.stdin.readline().strip())
  a = list(map(int, sys.stdin.readline().strip().split()))
  odds = even = 0
  for i in range(n):
    if i % 2 == 0 and a[i] % 2 != 0:
      even += 1
    if i % 2 == 1 and a[i] % 2 != 1:
      odds += 1
  print( -1 if odds != even else odds)