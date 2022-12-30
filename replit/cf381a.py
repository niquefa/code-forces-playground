import sys
sys.stdin.readline()
d = list(map(int, sys.stdin.readline().strip().split()))

s = a = 0
left_index = 0
right_index = len(d) - 1
s_turn = True
while left_index <= right_index:
  to_add = 0
  if d[left_index] > d[right_index] :
    to_add = d[left_index]
    left_index += 1
  else:
    to_add = d[right_index]
    right_index -= 1
  if s_turn:
    s += to_add
  else:
    a += to_add
  s_turn = not s_turn
print(f"{s} {a}")