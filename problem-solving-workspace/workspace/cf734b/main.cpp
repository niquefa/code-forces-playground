#include <bits/stdc++.h>
using namespace std;


void solve() {
  long long k2, k3, k5, k6;
  cin >> k2 >> k3 >> k5 >> k6;
  long long ans = 0;

  ans += 256 * min(k2, min(k5, k6));

  k2 -= min(k2, min(k5, k6));

  if( k2 > 0 ) {
    ans += 32 * min(k2, k3);
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  //cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  return 0;
}
