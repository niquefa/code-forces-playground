#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

long long sum_to_n_1( const long long& n ) {
  return n * (n-1)/2;
}

long long build_path( const long long& n, const long long& m ) {
  return m - 1 + (m * (n-1));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    long long n, m, k;
    cin >> n >> m >> k;
    if( n == 1 ) {
      cout << ( k == m - 1 ? "YES" : "NO" )<< endl;
      continue;
    }
    if( m == 1 ) {
      cout << ( k == n - 1 ? "YES" : "NO" )<< endl;
      continue;
    }
    long long path = build_path( n, m );
    long long path2 = build_path( m, n );
    debug(n, m, k, path, path2);
    cout << ( path == k || path2 == k ? "YES" : "NO") << endl;
  }
  return 0;
}
