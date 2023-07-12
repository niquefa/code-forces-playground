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
    long long n;
    cin >> n;
    long long ans = 0;
    if( n == 1LL ) {
      cout << 0 << endl;
      continue;
    }
    for( long long distance = 1; ; ++distance ) { 
      long long to_one_side = 2 * distance - 1;
      long long to_add = distance * (4 + to_one_side  * 4);
      //debug(distance, to_one_side, to_add);
      ans += to_add;
      if( to_one_side + 2 == n ) break;
    }
    cout << ans << endl;
  }
  return 0;
}
