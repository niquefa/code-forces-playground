import sys
a = []
for i in range(1,10):
  for j in range(1,5):
    a.append(j*str(i))
  

for _ in range(int(sys.stdin.readline().strip())):
  n = int(sys.stdin.readline().strip())
  ans = 0
  for x in a:
    ans +=  len(x)
    if n == int(x):
      break
  print(ans)