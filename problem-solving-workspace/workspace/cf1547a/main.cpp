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
    int xa, ya, xb, yb, xf, yf;
    cin >> xa >> ya >> xb >> yb >> xf >> yf;
    if( xa == xb && xb == xf ) {
      if( yf > min(ya, yb) && yf < max(ya, yb) ) {
        cout << abs(ya - yb) + 2 << '\n';
      } else {
        cout << abs(ya - yb) << '\n';
      }
      continue;
    }
    if( ya == yb && yb == yf ) {
      if( xf > min(xa, xb) && xf < max(xa, xb) ) {
        cout << abs(xa - xb) + 2 << '\n';
      } else {
        cout << abs(xa - xb) << '\n';
      }
      continue;
    }
    cout << abs(xa - xb) + abs(ya - yb) << '\n';
  }
  return 0;
}
