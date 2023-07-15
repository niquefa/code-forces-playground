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
  int test__cases;
  cin >> test__cases;
  for( int current__test = 0; current__test < test__cases; ++ current__test ) {
    int n;
    cin >> n;
    vector<int> a(n);
    for( int i = 0; i < n; ++ i) cin >> a[i];
    int ans = 0;
    for( int i = 0; i < n - 1 ; ++ i ) {
      int big_number = max(a[i], a[i+1]);
      int small_number = min(a[i], a[i+1]);
      if( big_number <= 2 * small_number ) continue;
      int counter = 0;
      while(big_number > 2 * small_number ) {
        big_number = (big_number / 2) + (big_number % 2);
        ++ counter;
      }
      debug(i, big_number, small_number, counter );
      ans += counter;
    }
    cout << ans << endl;
  }
  return 0;
}
