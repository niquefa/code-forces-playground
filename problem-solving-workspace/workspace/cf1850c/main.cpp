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
    int n = 8;
    vector<string> a(n);
    for( int i = 0; i < n; ++ i) cin >> a[i];
    string word = "";
    bool found = false;
    for( int i = 0; i < n && !found; ++ i ) {
      for( int j = 0; j < n && !found; ++ j ) {
        if( a[i][j] != '.' ) {
          found = true;
          for( int k = i; k < n; ++ k ) {
            if( a[k][j] != '.' ) {
              word += a[k][j];
            } else {
              break;
            }
          }
        }
      }
    }
    cout << word << endl;
  }
  return 0;
}
