import sys
test_cases = int(sys.stdin.readline().strip())
for _ in range(test_cases):
  n = int(sys.stdin.readline().strip())
  a = list(map(int, sys.stdin.readline().strip().split()))
  most_frequent = a[0]
  if a[1] == a[2] and a[1] != a[0]:
    most_frequent = a[1]
  for i in range(len(a)):
    if a[i] != most_frequent:
      print(i+1)
      break