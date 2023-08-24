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

long long work(long long k, long long n) {
  return (k * (k - 1)) / 2 >= n;
}
bool work_exactly(long long k, long long n) {
  return (k * (k - 1)) / 2 == n;
}
void solve() {
  long long n;
  cin >> n;
  
  long long lo = 0, hi = 3000000000;
  while (hi - lo > 1) {
    long long mid =(lo + hi) / 2;
    if (work(mid,n)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  if(work_exactly(lo,n)) {
    cout << lo << '\n';
    return;
  }
  if(work_exactly(hi,n)) {
    cout << hi << '\n';
    return;
  }
  debug(lo,hi);
  long long missingHi = n - (lo * (lo - 1)) / 2;
  cout << lo + missingHi << '\n';
}

