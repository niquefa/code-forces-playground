#include <bits/stdc++.h>
using namespace std;



void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];
  long long answer = 0;
  for( int i = 1; i < n; ++ i ) 
    answer = max( answer , a[i] * a[i-1] );

  cout << answer << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  return 0;
}
