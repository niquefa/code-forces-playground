#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


void solve();
int main() {
  auto start_execution_time = std::chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = std::chrono::high_resolution_clock::now();

  chrono::duration<double, std::milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
void solve() {
  int n, d;
  cin >> n >> d;
  string s;
  cin >> s;
  if( d == 0 ) {
    cout << s << d << endl;
    return;    
  }
  if( d == 9 ) {
    cout << d << s << endl;
    return;
  }
  bool found = false;
  for( int i = 0; i < n; ++ i ) {
    if( !found && s[i] - '0' < d ) {
      cout << d;
      found = true;
    }
    cout << s[i];
  }
  if( !found ) 
    cout << d;
  cout << endl;
}
