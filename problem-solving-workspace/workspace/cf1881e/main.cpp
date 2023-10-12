#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");

vector<int> a;
vector<int> dp;

int min_operations(int idx) {
  if (idx >= (int)a.size()) return 0;
  
  if (dp[idx] != -1) return dp[idx];
  
  int option1 = 1 + min_operations(idx + 1);
  
  int option2 = INT_MAX;
  if (idx + a[idx] < (int)a.size()) 
    option2 = min_operations(idx + a[idx] + 1);
  
  
  return dp[idx] = min(option1, option2);
}

void solve() {
  int n;
  cin >> n;
  a.resize(n);
  for(int i = 0; i < n; ++i) cin >> a[i];
  dp.assign(n + 1, -1);
  //va(a);
  
  cout << min_operations(0) << "\n";
}

int main() {
  auto start_execution_time = chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for(int current_test = 1; current_test <= test_cases; ++current_test) {
    //cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
