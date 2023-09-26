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
int find_interval(const vector<pair<int, int>>& intervals, int X) {
  int left = 0;
  int right = intervals.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (intervals[mid].first <= X && intervals[mid].second >= X) {
      return mid;
    } else if (intervals[mid].first > X) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return -1;
}

void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<int> l(k);
  for( int i = 0; i < k; ++ i) cin >> l[i];
  vector<int> r(k);
  for( int i = 0; i < k; ++ i) cin >> r[i];

  vector<pair<int,int> > intervals;
  for( int i = 0; i < k; ++ i) intervals.push_back({l[i], r[i]});
  
  sort(intervals.begin(), intervals.end());


  int q;
  cin >> q;
  vector<int> modifications(q);

  for( int i = 0; i < q; ++ i) cin >> modifications[i];

  va(modifications);

  for( auto &x : modifications) {
    int i = find_interval(intervals, x);

    int a = min(x, intervals[i].first + intervals[i].second - x)-1;
    int b = max(x, intervals[i].first + intervals[i].second - x)-1;
    reverse(s.begin() + a, s.begin() + b + 1);
  }
  cout << s << endl;
}