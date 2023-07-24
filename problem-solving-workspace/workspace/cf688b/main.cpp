#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;
  cout << s;
  reverse(s.begin(), s.end());
  cout << s << endl;
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
