import sys
m = {}
for _ in range(int(sys.stdin.readline().strip())):
  k = sys.stdin.readline()
  m[k] = m[k] + 1 if k in m else 1
print(max(m, key = m.get))