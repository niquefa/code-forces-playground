#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

template<class T> void print_vector(const vector<T>& c, const string& vector_name = "") {
  cerr << (!vector_name.empty() ? vector_name : "Vector : ") << "[ ";
  for(auto it = c.begin(); it != c.end(); ++it) {
    if (it != c.begin())
      cerr << " , ";
    cerr << *it;
  }
  cerr << " ] " << c.size() << " Elements." << endl;
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
int get_max_prefix_sum(const vector<int>& v) {
  vector<int> ans(v.size());
  ans[0] = v[0];
  for( int i = 1; i < v.size(); ++ i) {
    ans[i] = ans[i - 1] + v[i];
  }
  return max(0,*max_element(ans.begin(), ans.end()));
}
//max prefix sum
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];
  int m;
  cin >> m;
  vector<int> b(m);
  for( int i = 0; i < m; ++ i) cin >> b[i];
  debug(n,m);
  print_vector(a);
  print_vector(b);
  int max_sum_a = get_max_prefix_sum(a);
  int max_sum_b = get_max_prefix_sum(b);
  cout << max_sum_a + max_sum_b << endl;
}
