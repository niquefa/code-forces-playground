import sys
t = [0]
candidate = 0
while len(t) < 1010 :
  candidate += 1
  if candidate % 3 == 0 or candidate % 10 == 3:
    continue
  t.append(candidate)
n = int(sys.stdin.readline().strip())
for _ in range(n):
  k = int(sys.stdin.readline().strip())
  print(t[k])