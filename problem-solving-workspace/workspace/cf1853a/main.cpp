#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];
  bool already_sorted = true;
  for( int i = 1; i < n; ++ i ) if( a[i] < a[i-1] ) already_sorted = false;
  if( !already_sorted ) {
    cout << 0 << endl;
    return;
  }
  vector<long long> differences;
  for( int i = 1; i < n; ++ i )
    differences.push_back(abs(a[i] - a[i-1]));
  long long max_diff = *min_element(differences.begin(), differences.end());
  if( max_diff <= 1 ) {
    cout << 1 << endl;
    return;
  }
  if( max_diff == 2 ) {
    cout << 2 << endl;
    return;
  }
  max_diff ++;
  long long answer = max_diff / 2L + (max_diff % 2L);
  cout << answer << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    solve();
  }
  return 0;
}
