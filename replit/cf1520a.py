import sys
t = int(sys.stdin.readline().strip())
for _ in range(t):
  n = int(sys.stdin.readline().strip())
  w = sys.stdin.readline().strip()
  tasks = set(list(w))
  s = "_" + w + "_"
  flag = False
  for separator in tasks:
    ss = s.replace(separator, " ")
    a = ss.split()
    if len(a) != 2 :
      flag = True
      break
  print( "NO" if flag else "YES")
  