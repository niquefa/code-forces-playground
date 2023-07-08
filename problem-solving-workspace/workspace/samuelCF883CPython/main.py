from sys import stdin


def best(times, h, i):
    if len(times) == 1:
        if times[0] > h:
            return (0, 0, i)
        else:
            return (-1, times[0], i)
    solved_problems = 0
    penalty = [0 for _ in range(len(times))]
    penalty[0] = times[0]
    # print("In best")
    # print(times)
    # print(i,penalty)
    for q in range(1, len(times)):
        penalty[q] = penalty[q-1] + times[q]
    #print(i,penalty)        
    for j in range(len(times)):
        if penalty[j] <= h:
            solved_problems += 1
        else:
            break
    print("value", j)
    return (-solved_problems, sum(penalty[:solved_problems]), i)


def main():
    t = int(stdin.readline().strip())
    for KK in range(t):
        n, _, h = list(map(int, stdin.readline().strip().split()))
        scores = []
        #print("\n\n\nCase",KK,h)

        for i in range(n):
            times = list(map(int, stdin.readline().strip().split()))
            times.sort()
            b = best(times, h, i)
            #print(i,b)
            scores.append(b)
        scores.sort()
        #print(scores)
        for k in range(len(scores)):
            if scores[k][2] == 0:
                print(k+1)
                break

    
if __name__ == "__main__":
    main()
