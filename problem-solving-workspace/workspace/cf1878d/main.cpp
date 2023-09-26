#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");


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
int f( const vector<int>& a, const int l, const int r ) {
  int ans = a[l];
  for( int i = l + 1; i <= r; ++ i ) 
    ans &= a[i];
  
  return ans;
}
vector<vector<int>> buildSparseTable(const vector<int>& a) {
  int n = a.size();
  int max_log = log2(n) + 1;

  vector<vector<int>> st(n, vector<int>(max_log));

  // Base cases
  for (int i = 0; i < n; i++)
    st[i][0] = a[i];

  for (int j = 1; j <= max_log; j++) {
    for (int i = 0; i + (1 << j) <= n; i++) {
      st[i][j] = st[i][j-1] & st[i + (1 << (j - 1))][j-1];
    }
  }

  return st;
}
int query(const vector<vector<int>>& st, int l, int r) {
    int len = r - l + 1;
    int k = log2(len);
    return st[l][k] & st[r - (1 << k) + 1][k];
}

void solve() {
  int n, Q;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  
  auto st = buildSparseTable(a);
  
  cin >> Q;
  for (int i = 0; i < Q; ++i) {
    int l, k;
    cin >> l >> k;
    l--;

    int max_r = -1;
    int curr_r = l;

    for (int jump = log2(n); jump >= 0; --jump) {
      if (curr_r + (1 << jump) - 1 < n && query(st, l, curr_r + (1 << jump) - 1) >= k) {
        curr_r += (1 << jump);
        max_r = curr_r;
      }
    }

    cout << (max_r != -1 ? max_r : -1) << " ";
  }
  cout << endl;
}
