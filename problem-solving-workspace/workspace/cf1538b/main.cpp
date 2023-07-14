#include <bits/stdc++.h>
using namespace std;


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
    
    long long sum = 0;
    for( int i = 0; i < n; ++ i) sum += a[i];

    if( sum % n != 0 ) {
      cout << -1 << endl;
      continue;
    }
    int ans = 0;
    for( int i = 0; i < n; ++ i) ans += a[i] > sum / n ? 1 : 0;

    cout << ans << endl;
  }
  return 0;
}
