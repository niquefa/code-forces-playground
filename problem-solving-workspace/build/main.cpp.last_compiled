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
  string s;
  cin >> n >> s;
  map<char,int> fa;
  map<char,int> fb;
  int ans = fb.size();
  for( char c : s ) 
    fb[c] ++;
  for( int i = 0; i < s.size()-1; ++ i ){
    
    char c = s[i];
    fb[c]--;
    if( fb[c] == 0 ) {
      fb.erase(c);
    }
    fa[c]++;

    if( fa.size() > 0 && fb.size() > 0  ) {
      ans = max(ans, (int)fa.size()+(int)fb.size() );
    }
  }

  cout << ans << endl;
}
