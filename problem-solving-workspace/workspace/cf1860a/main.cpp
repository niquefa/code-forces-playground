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
  string s;
  cin >> s;
  if( s == "()") {
    cout << "NO" << endl;
    return;
  }
  if( s == ")(") {
    cout << "YES" << endl << "(())" << endl;
    return;
  }
  cout << "YES" << endl;
  for( int i = 3; i < s.size(); ++ i ) {
    if( s[i-3] == '(' && s[i-2] == ')' && s[i-1] == '(' && s[i] == ')' ) {
      for( int j = 0;j < s.size(); ++ j )cout << "(";
      for( int j = 0;j < s.size(); ++ j )cout << ")";
      cout << endl;
      return;
    }
  }
  for( int i = 1; i < s.size(); ++ i ) {
    if( s[i-1] == ')' && s[i] == '(' ) {
      for( int j = 0;j < s.size(); ++ j )cout << "(";
      for( int j = 0;j < s.size(); ++ j )cout << ")";
      cout << endl;
      return;
    }
  }
  
  for( int i = 0;i < s.size(); ++ i ) {
    if( s[i] == '(' ) {
      cout << "()";
    } else {
      cout << "()";
    }
  }
  cout << endl;
}
