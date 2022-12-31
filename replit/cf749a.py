import sys

n = int(sys.stdin.readline().strip())
a = []
if n % 2 == 1 :
  a.append(3)
  n -= 3
while n > 0 :
  n -= 2
  a.append(2)
print(len(a))
print(*a, sep = " ")
  