import sys
n = int(sys.stdin.readline().strip())
b = sorted(list(map(int, sys.stdin.readline().strip().split())))
b.append(int(10e10))
q = int(sys.stdin.readline().strip())
for _ in range(q):
  c = int(sys.stdin.readline().strip())
  start = 0
  end = len(b)-1
  ans = -1
  while start <= end:
    mid = (start + end) // 2

    if b[mid] <= c:
      start = mid + 1
    else:
      ans = mid
      end = mid - 1

  print(ans if ans >= 0 else 0)