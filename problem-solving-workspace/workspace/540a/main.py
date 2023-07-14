import sys

def I(): return int(sys.stdin.readline().strip())
def S(): return sys.stdin.readline().strip()
  
def main():
  n = I()
  initial = S()
  target = S()
  answer = 0
  for i in range(n):
    optionA = 0
    startNumber = int(initial[i])
    while( startNumber != int(target[i]) ):
      if startNumber == 0:
        startNumber = 9
      else:
        startNumber -= 1
      optionA += 1
    
    optionB = 0
    startNumber = int(initial[i])
    while( startNumber != int(target[i]) ):
      if startNumber == 9:
        startNumber = 0
      else:
        startNumber += 1
      optionB += 1
    
    answer += min(optionA, optionB)
  print(answer)
if __name__ == "__main__":
  main()