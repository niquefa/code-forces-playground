#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long r, b, d;
  cin >> r >> b >> d;
  long long mn = min(r, b);
  long long mx = max(r, b);

  long long max_difference = -1 + mx / mn + (mx % mn != 0);

  cout << (max_difference <= d ? "YES" : "NO") << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  return 0;
}
