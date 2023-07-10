#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
//2 pointers
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for( int i = 0; i < n; ++ i) cin >> a[i];

    debug("Case ", test);

    bool positive_sequence = a[0] > 0;
    int index = 0;
    long long ans = 0;
    while(index < n) {
      long long best = a[index];
      if( positive_sequence ) {
        while( index < n && a[index] > 0 )
          best = max(best, a[index++]);
      } else {
        while( index < n && a[index] < 0 )
          best = max(best, a[index++]);
      }
      debug(index, best);
      ans += best;
      positive_sequence = !positive_sequence;
    }
    cout << ans << endl; 
  }
  return 0;
}
