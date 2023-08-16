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
  int n, a;
  cin >> n;
  vector<int> c(3,0);
  int s = 0;
  for( int i = 0; i < n; ++ i){
    cin >> a;
    c[a % 3] ++;
    s += a;
  }
  int m = n/3;
  debug(n,m);
  int ops = 0;
  while(true) {
    set<int> sc(c.begin(),c.end());

    if( sc.size() == 1 ) {
      cout << ops << endl;
      return;
    }
    for( int i = 0; i < 3; ++i ) {
      if( c[i] > m ) {
        int d = c[i] - m;
        c[i] -= d;
        c[(i+1)%3] += d;
        ops += d;
        break;
      }
    }
  }
}
