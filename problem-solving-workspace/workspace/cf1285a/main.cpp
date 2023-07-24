#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


map<char,int> get_char_frequencies( const string& v ){map<char,int> ans;for( int i = 0; i < v.size(); ++ i )ans[v[i]]++;return ans;}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<char,int> m = get_char_frequencies(s);
  cout << m['L'] + m['R'] + 1 << endl;
}

int main() {
  auto start_execution_time = std::chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  //cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = std::chrono::high_resolution_clock::now();

  chrono::duration<double, std::milli> elapsed = start_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
