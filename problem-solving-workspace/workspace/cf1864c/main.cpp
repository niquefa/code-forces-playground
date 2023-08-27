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
  int x;
  cin >> x;
  int l = 1;
  for( int bit = 30; bit > 0; -- bit ) {
    if( ((1 << bit)) <= x ) {
      l = bit;
      break;
    }
  }
  
  
  vector<int> ans;
  ans.push_back(x);
  for( int bit = 0; bit < l - 1; ++ bit ) {
    if( (1 << bit) & x ) {
      x -= (1 << bit);
      ans.push_back(x);
      
    }
  }

  while( l > 0 ) {
    x -= (1<<(l-1));
    ans.push_back(x);
    --l;
  }
  sort(ans.rbegin(), ans.rend());
  if( ans[ans.size() - 1] != 1 ){
    ans.push_back(1);
  }
  sort(ans.rbegin(), ans.rend());
  debug(x,l);
  va(ans)

  cout << ans.size() << endl;
  for( int i = 0; i < ans.size(); ++ i ) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
