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
bool all_zeroes(vector<int>& a) {
  for( int i = 0; i < a.size(); ++ i) 
    if( a[i] != 0 ) return false;
  
  return true;
}
void f_xor(vector<int>& a, int l, int r ) {
  int x = a[l];
  for( int i = l+1; i <= r; ++ i) {
    x ^= a[i];
  }
  for( int i = l; i <= r; ++ i) {
    a[i] = x;
  }
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];

  if( all_zeroes(a) ) {
    cout << 0 << endl;
    return;
  }
  va(a);
  if( n%2 == 0 ) {
    cout << 2 << endl;
    cout << 1 << " " << n << endl;
    cout << 1 << " " << n << endl;
    // f_xor(a, 0, n-1);
    // f_xor(a, 0, n-1);
    // debug("EVEN");
    // va(a);
    return;
  }
  cout << 4 << endl;
  cout << 2 << " " << n << endl;
  cout << 2 << " " << n << endl;
  cout << 1 << " " << 2 << endl;
  cout << 1 << " " << 2 << endl;
  // f_xor(a, 1, n-1);
  // f_xor(a, 1, n-1);
  // f_xor(a, 0, 1);
  // f_xor(a, 0, 1);

  // debug("ODD");
  // va(a);
}
