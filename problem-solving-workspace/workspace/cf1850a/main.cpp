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
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    int n = 3;
    vector<int> a(3);
    bool solution = false;
    for( int i = 0; i < n; ++ i) cin >> a[i];

    for( int i = 0; i < n; ++ i)
      for( int j = 0; j < n; ++ j ) {
        if( i != j && a[i] + a[j] >= 10 ) {
          solution = true;
        }
      }
    cout << (solution ? "YES" : "NO") << endl;
  }
  return 0;
}
