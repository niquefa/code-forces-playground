import sys

m, s = map(int, sys.stdin.readline().strip().split())

if s == 0 :
  if m == 1 :
    print("0 0")
  else :
    print("-1 -1")
elif s > 9 * m:
  print("-1 -1")
else :
  max = ""
  ss = 0
  for _ in range(m):
    for i in range(9,-1,-1):
      if ss + i <= s:
        max += str(i)
        ss += i
        break
  min = ""
  ss = 0
  for _ in range(m-1):
    for i in range(9,-1,-1):
      if ss + i <= s :
        min = str(i) + min
        ss += i
        break
  if ss < s :
    min = str(s-ss) + min
  else :
    first_non_0_index = 0
    for i in range(len(min)):
      if min[i] != "0" :
        first_non_0_index = i
        break
    min = "1" + min[0:first_non_0_index] + str(int(min[first_non_0_index])-1) + min[first_non_0_index+1:]
  print(f"{min} {max}")