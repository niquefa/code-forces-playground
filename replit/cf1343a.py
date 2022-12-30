import sys
t = int(sys.stdin.readline().strip())
for _ in range(t):
  n = int(sys.stdin.readline().strip())
  k = 2
  answer = -1
  while True:
    if answer != -1 :
      break
    denominator = (1<<k) - 1
    if n % denominator == 0 :
      answer = n//denominator
      break
    k += 1
  print(answer)