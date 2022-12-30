import sys
from collections import Counter
for _ in range(int(sys.stdin.readline().strip())):
  n = int(sys.stdin.readline().strip())
  a = Counter(list(map(int, sys.stdin.readline().strip().split())))
  if (a[1] + 2*a[2]) % 2 == 1:
    print("NO")
  elif a[2] % 2 == 1:
    if a[1] >= 2 :
      print("YES")
    else:
      print("NO")
  else:
    print("YES")