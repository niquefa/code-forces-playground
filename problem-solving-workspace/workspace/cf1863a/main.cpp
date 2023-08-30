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
  int n,a,q;
  string s;
  cin >> n >> a >> q >> s;
  debug(n,a,q,s);
  if( n == a ) {
    cout << "YES" << endl;
    return;
  }
  bool f = false;
  int na = 0;
  int oa = a;
  int no = 0;
  for( int i = 0; i < q; ++ i ) {
    if( s[i] == '+'){
      na++;
      a++;
    } else {
      no++;
      a--;
      f = true;
    }
    if( a >= n && !f) {
      //debug(i,a,n);
      cout << "YES" << endl;
      return;
    }
    if( oa + na - no >= n ) {
      cout << "YES" << endl;
      return;
    }
  }
  //debug(na);
  if( oa + na >= n) {
    cout << "MAYBE" << endl;
    return;
  }
  cout << "NO" << endl;
  
}
