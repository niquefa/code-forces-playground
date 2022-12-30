import sys
n = int(sys.stdin.readline().strip())
mw = cw = 0

for i in range(n):
  m, c = map(int, sys.stdin.readline().strip().split())
  if m > c :
    mw += 1
  elif c > m :
    cw += 1

if mw == cw :
  print("Friendship is magic!^^")
elif mw > cw :
  print("Mishka")
else :
  print("Chris")