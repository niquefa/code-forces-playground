#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve() {
  long long a, b, n, s;
  cin >> a >> b >> n >> s;
  if( a * n + b < s ) {
    cout << "NO" << endl;
    return;
  }

  if( b >= s || ( s % n == 0 && s / n <= a ) ){
    cout << "YES" << endl;
    return;
  }
  long long x = s / n;
  long long y = s % n;
  long long s_left = s - x*n;
  debug(a,b,n,s,x,y,s_left);
  cout << (s_left <= b ? "YES" : "NO") << endl;
}

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

  chrono::duration<double, std::milli> elapsed = start_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
