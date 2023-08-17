#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

template<typename T>T iceil(T n, T d) {
  if (d == 0) throw runtime_error("Division by zero!");
  if (n < 0 || d < 0) return (n + ((d > 0) ? 0 : (d + 1))) / d;
  return (n + d - 1) / d;
}

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
long long m, k, a1, ak;
void solve() {
  cin >> m >> k >> a1 >> ak;
  debug(m,k,a1,ak);
  long long normal_coins = a1 + ak * k;

  if (m == normal_coins) {
    debug("m === normal_coins");
    cout << 0 << endl;
  } else {
    long long max_ak_used = max(0LL , min(m/k , iceil(m-a1,k)) );
    long long answer = max(0LL,max_ak_used - ak) + max(0LL,m-max_ak_used*k-a1);
    cout << answer << endl;
  }
}
