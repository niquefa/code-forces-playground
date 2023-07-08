# from sys import stdin
# test_cases = int(stdin.readline().strip())
# for _ in range(test_cases):
#     flag = False
#     n = int(stdin.readline().strip())
#     for i in range(2,1000):
        
#         vertex = i + 1
#         for j in range(2,n):
#             vertex += i**j
#             #print('Segundo ciclo: sec:', sec,'n:',n, 'i:', i, 'k:', k,flag)
#             if vertex == n:
#                 flag = True
#                 #print('sec igual n')
#                 break
#             if vertex > n:
#                 break
#         if flag:
#             break
 
#     if flag:
#         print('YES')
#     else:
#         print('NO')
#     #print(sec,sec==n)



# from sys import stdin
# test_cases = int(stdin.readline().strip())
# for _ in range(test_cases):
#     n = int(stdin.readline().strip())
#     sec = 7
#     for k in range(2,1000):
#         if k > n:
#             break
#         flag = False
#         i = 3
#         sec = k**2 + k + 1
#         #print('Primer ciclo: sec:',sec,'n:',n,  'i:', i, 'k:', k,flag)
#         if sec == n:
#             flag = True
#             #print('sec igual n')
#             break
#         for i in range(3,n):
#             sec = sec + k**i
#             #print('Segundo ciclo: sec:', sec,'n:',n, 'i:', i, 'k:', k,flag)
#             if sec == n:
#                 flag = True
#                 #print('sec igual n')
#                 break
#             if sec > n:
#                 break
#         if flag:
#             break
 
#     if sec != n:
#         print('NO')
#     else:
#         print('YES')
#     #print(sec,sec==n)

t = int(input())
a = set()
for k in range(2, 1000):
    for e in range(2, 100):
        x = 1 + k + k**2
        if x > 1e6:
            break
        else:
            a.add(x)
for _ in range(t):
    n = int(input())
    if n in a:
        print("YES")
    else:
        print("NO")