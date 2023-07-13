#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n, k;
    cin >> n >> k;
    if( k > n ) {
      cout << "NO" << endl;
      continue;
    }
    if( k == n ) {
      cout << "YES" << endl;
      for( int i = 0; i < n; ++ i ) 
        cout << 1 << " ";
      cout << endl;
      continue;
    }
    int a_value = (n-k+1);
    int b_value = (n-((k-1)*2));
    bool option_a = a_value > 0 && a_value % 2 == 1;
    bool option_b = b_value > 0 && b_value % 2 == 0;
    debug(n,k,option_a,option_b);
    if( option_a ) {
      cout << "YES" << endl;
      cout << a_value << " ";
      for( int i = 0; i < k-1; ++ i ) 
        cout << 1 << " ";
      cout << endl;
    } else if( option_b ) {
      cout << "YES" << endl;
      cout << b_value << " ";
      for( int i = 0; i < k-1; ++ i ) 
        cout << 2 << " ";
      cout << endl;
    } else {
      cout << "NO" << endl;
    }

  }
  return 0;
}
