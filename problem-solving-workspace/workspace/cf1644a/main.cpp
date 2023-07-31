#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve();
int main() {
  auto start_execution_time = chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}

int find_first_char(const string& str, char c) {
    auto it = find(str.begin(), str.end(), c);
    return it == str.end() ? - 1 : distance(str.begin(), it);
}
void solve() {
  const string lower = "rgb";
  const string upper = "RGB";
  bool f = true;
  string s;
  cin >> s;
  for( int i = 0; i < lower.size(); ++ i ) {
    int a = find_first_char(s, lower[i]);
    int b = find_first_char(s, upper[i]);
    if( b < a ) {
      f = false;
      break;
    }
  }
  cout << (f ? "YES" : "NO") << endl;
}
