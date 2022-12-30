import sys
n = int(sys.stdin.readline().strip())
if n >= 0 :
  print(n)
else:
  n = abs(n)
  if n < 10:
    print(0)
  else:
    print(f"{-1*int(n//100*10 + min(n%10, n//10% 10))}")