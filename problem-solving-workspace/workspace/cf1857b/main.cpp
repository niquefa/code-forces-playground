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
void solve() {
  string x;
  cin >> x;
  if( x.size() == 1 ) {
    cout << (x[0] <= '4' ? x :"10") << endl;
    return;
  }
 

  int index = -1;
  for( int i = 0; i < x.size(); ++ i ) {
    if( x[i] >= '5' ) {
      index = i;
      break;
    }
  }
  if( index == -1 ) {
    cout << x << endl;
    return;
  }
  string prefix = "";
  string suffix = "";
  string ss = "";
  for( int i = index+1; i < x.size(); ++ i ) {
    suffix += '0';
  }

  
  x = "0" + x;
  index ++;
  //debug(index,x,x[index]);
  
  for( int i = index; i >= 0; -- i ) {
    if( x[i] >= '4' ) {
      ss += '0'; 
    } else {
      ss =  string(1,x[i] + 1) + ss;
      for( int j = i-1; j >= 0 ; --j ) {
        prefix = string(1,x[j]) + prefix;
      }
      break;
    }
  }
  //debug(x, prefix, ss ,suffix);
  string ans = prefix + ss + suffix;
  if( ans[0] == '0' ) 
    ans = ans.substr(1);
  
  cout << ans << endl;

}
