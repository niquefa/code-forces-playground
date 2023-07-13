#include <bits/stdc++.h>

using namespace std;

bool solve_first_m(int n, int m, int x) {
    while(n > 0 || m > 0) {
      if( x <= 0 )break;
      if( n > 0 && m > 0 ) {
        x -= 10;
        m --;
        continue;
      }
      if( n > 0 )
        x = x/2 + 10, n --;
      if( m > 0 )
        x -= 10, m --;
    }
    return x <= 0;
}

bool solve_first_n(int n, int m, int x) {
    while(n > 0 || m > 0) {
      if( x <= 0 )break;
      if( n > 0 && m > 0 ) {
        x = x/2 + 10;
        n --;
        continue;
      }
      if( n > 0 )
        x = x/2 + 10, n --;
      if( m > 0 )
        x -= 10, m --;
      
    }
    return x <= 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int x, n, m;
    cin >> x >> n >> m;
    cout << (solve_first_m(n,m,x) || solve_first_n(n,m,x) ? "YES" : "NO") << '\n';

  }
  return 0;
}
