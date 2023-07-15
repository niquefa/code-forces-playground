#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

bool check(long long x) {
    long long upper = cbrt(x) + 1;
    debug(x, upper);
    for(long long a = 1; a < upper; a++) {
        long long b_cubed = x - a*a*a;
        if(b_cubed <= 0) break;
        
        double b = cbrt(b_cubed);

        if( abs(trunc(b) - b) <= 1e-10 ) {
          //debug(x,a, b, b*b*b, b_cubed);
          return true;
        }
            
    }
    return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int current_test = 0; current_test < test_cases; ++ current_test ) {
    long long x;
    cin >> x;
    cout << (check(x) ? "YES" : "NO") << endl;
  }
  return 0;
}
