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
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];
  if( n == 1 ) {
    cout << a[0] << endl;
    return ;
  }
  set<int> s(a.begin(), a.end());
  if( s.size() == 1 ) {
    cout << (a[0] > 0 ? a[0] : 0 ) << endl;
    return ;
  }
  sort(a.begin(), a.end());
  int lower = a[0];
  if( lower < 0 ) 
    for( auto &x: a )
      x -= lower;
  vector<int> b;
  for( auto x : a ) if( x > 0 ) b.push_back(x);
  if( b.size() == 1 ) {
    cout << b[0] << endl;
    return ;
  }
  s = set<int>(b.begin(), b.end());
  if( s.size() == 1 ) {
    cout << (b[0] > 0 ? b[0] : 0 ) << endl;
    return ;
  }
  int ans = b[0];
  for( int i = 1; i < b.size(); i ++ ) {
    int diff = b[i] - b[i-1];
    if( diff > ans ) {
      ans = diff;
    }
  }
  
  cout << ans << endl;
}
