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
  //cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  long long ans = 0;
  long long zeros = 0;
  long long negatives = 0;
  long long positives = 0;
  for( int i = 0; i < n; ++ i) {
    cin >> a[i];
    if( a[i] == 0 ) ++ zeros;
    else if( a[i] < 0 ) ++ negatives;
    else ++ positives;

    if( a[i] < 0 ) {
      ans += -1 - a[i];
    }
    if( a[i] > 0 ) {
      ans += a[i] - 1;
    }
    if( a[i] == 0 ) {
      ans += 1;
    }
  }
  if( negatives % 2 == 0 ){ 
    cout << ans << endl;
    return;
  }
  if( zeros > 0 ) {
    cout << ans << endl;
    return;
  }
  cout << ans + 2 << endl;
  
}
