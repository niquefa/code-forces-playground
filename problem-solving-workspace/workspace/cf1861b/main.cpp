#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

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
#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");

void solve() {
  string a, b;
  cin >> a >> b;
  if( a == b ) {
    cout << "YES" << endl;
    return;
  }
  int n = (int)a.size();
  vector<int> closestOneToTheRight(n,n-1);
  for( int i = n-2; i >= 0 ; --i ) {
    if( a[i] == '0' || b[i] == '0' ) {
      closestOneToTheRight[i] = closestOneToTheRight[i+1];
    } else {
      closestOneToTheRight[i] = i;
    }
  }
  for( int i = 0;i < n-1; ++i ) {
    if( a[i] == '1' || b[i] == '1' ) {
      continue;
    }
    if( closestOneToTheRight[i+1] == i+1 ) {
      cout << "YES" << endl;
      return;
    }
  }
  //debug(a);
  //debug(b);
  //va(closestOneToTheRight);
  cout << "NO" << endl;
}
