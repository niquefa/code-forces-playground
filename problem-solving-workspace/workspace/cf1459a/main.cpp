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
void solve() {
  bool yes = true;
  string s;
  cin >> s;
  int n = s.size();
  for( int i = 0 ; i < n; ++ i ) {
    if( s[i] != 'Y' && s[i] != 'e' && s[i] != 's' ) {
      yes = false;
      break;
    }
    if( s[i] == 'Y') {
      if( i+1 < n && s[i+1] != 'e' ) {
        yes = false;
        break;
      }
      if( i+2 < n && s[i+2] != 's' ) {
        yes = false;
        break;
      }
    }
    if( s[i] == 'e' ){
      if( i+1 < n && s[i+1] != 's' ) {
        yes = false;
        break;
      }
      if( i+2 < n && s[i+2] != 'Y' ) {
        yes = false;
        break;
      }
    }
    if( s[i] == 's' ){
      if( i+1 < n && s[i+1] != 'Y' ) {
        yes = false;
        break;
      }
      if( i+2 < n && s[i+2] != 'e' ) {
        yes = false;
        break;
      }
    }
  }

  cout << (yes ? "YES" : "NO") << endl;
}
