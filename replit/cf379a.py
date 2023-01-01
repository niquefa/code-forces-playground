import sys
a, b = map(int, sys.stdin.readline().strip().split())
c = a
h = 0
bo = 0
while a > 0 :
  h += 1
  a -= 1
  bo += 1
  if bo == b :
    bo = 0
    a += 1
print(h)