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
    //cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}

vector<long long> a;
vector<long long> prefix_sum;
int n,x;
bool can_fill( long long max_height ) {
  long long cols_with_water = distance(a.begin(), lower_bound(a.begin(), a.end(), max_height));
  long long cols_without_water = n - cols_with_water;
  long long water_needed = cols_with_water * max_height - (cols_with_water > 0 ? prefix_sum[cols_with_water-1] : 0);
  //debug(max_height, cols_with_water, cols_without_water, water_needed);
  return water_needed <= x;
}
void solve() {
  cin >> n >> x;
  a.resize(n);
  prefix_sum.resize(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];
  sort(a.begin(), a.end());
  for( int i = 0; i < n; ++ i) prefix_sum[i] = a[i] + (i > 0 ? prefix_sum[i-1] : 0);

  long long low = 0, high = 1LL<<40, result = 0;
  while(low <= high) {
    long long mid = (low + high) / 2;
    if(can_fill(mid)) {
      result = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  cout << result << endl;
}
