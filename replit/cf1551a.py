import sys
"""
for n in range(3, 100):
  best_diff = 9999
  x, y = -1, -1
  for a in range(n+1):
    for b in range(n+1):
      if a + 2*b != n :
        continue
      if abs(a-b) < best_diff :
        best_diff = abs(a-b)
        x, y = a, b
  print(f"For {n} {x} {y} {abs(y-x)} {n//3}  {(n//3) == x or (n//3) == y}")
"""
  
for _ in range(int(sys.stdin.readline().strip())):
  n = int(sys.stdin.readline().strip())
  best_diff = 9999
  x, y = -1, -1
  for c2 in range(n//3 - 2, n//3 + 2):
    c1 = n - 2*c2
    if c1 < 0 or c1 + 2*c2 != n:
      continue
    if abs(c1-c2) < best_diff :
      best_diff = abs(c1-c2)
      x, y = c1, c2
    
  print(f"{x} {y}")
  