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
  int a , b , c;
  cin >> a >> b >> c;
  if( a + c <= b ){
    cout << "Second\n";
    return;
  }
  if( b + c < a ) {
    cout << "First\n";
    return;
  }

  if(c % 2 == 0) {
    if(a > b ) cout << "First\n";
    else cout << "Second\n";
  } else {
    if(a >= b) cout << "First\n";
    else cout << "Second\n";
  }
}
