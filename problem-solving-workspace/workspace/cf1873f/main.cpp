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
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) 
    solve();
  
  auto finish_execution_time = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
int n, k;
vector<int> a;
vector<int> prefix_sum_of_a;
vector<int> h;
long long sum(int left_index, int right_index) {
  if( left_index == 0 ) return prefix_sum_of_a[right_index];
  return prefix_sum_of_a[right_index] - prefix_sum_of_a[left_index-1];
}
bool is_valid(int left, int right) {
  if (left == right) return true;
  return h[right - 1] % h[right] == 0;
}

void solve() {
  cin >> n >> k;
  a.resize(n);
  h.resize(n);
  prefix_sum_of_a.resize(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];
  for( int i = 0; i < n; ++ i) cin >> h[i];
  prefix_sum_of_a[0] = a[0];
  for( int i = 1; i < n; ++ i) prefix_sum_of_a[i] = prefix_sum_of_a[i-1] + a[i];

  // debug(n,k);
  // va(a);
  // va(h);
  // va(prefix_sum_of_a)
  // cerr << endl;


  int left = 0, right = 0;
  long long current_sum = 0;
  int answer = 0;

  while (right < n) {
    current_sum += a[right];

    while (left <= right && (current_sum > k || !is_valid(left, right))) {
      current_sum -= a[left];
      left++;
    }

    answer = max(answer, right - left + 1);
    right++;
  }

    cout << answer << "\n";
}