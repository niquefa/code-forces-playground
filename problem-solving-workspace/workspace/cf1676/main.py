import sys
 
def MI(): return map(int, sys.stdin.readline().strip().split())
def LI(): return list(map(int, sys.stdin.readline().strip().split()))

MAX = 201
dr = [-1,-1, 1,1]
dc = [-1, 1,-1,1]
g = [[0 for i in range(MAX)] for j in range(MAX)]
n = 0
m = 0

def ok( r , c , n, m):
  return r >= 0 and c >= 0 and r < n and c < m

def f(r, c, n, m):
  ans = g[r][c];
  for i in range(4):
    nr = r;
    nc = c;
    while True: 
      nr = nr + dr[i]
      nc = nc + dc[i]
      if not ok(nr,nc,n,m):
        break
      ans += g[nr][nc]
  return ans

def solve(n,m):
    for i in range(n):
        g[i] = LI()
    ans = 0
    for i in range(n):
        for j in range(m):
            test = f(i,j,n,m)
            if test > ans:
                ans = test
    print(ans)


def main():
    t = int(input())
    for i in range(t):
        n, m = MI()
        solve(n,m)

if __name__ == "__main__":
    main()