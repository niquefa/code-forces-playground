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

  string a;
  cin >> a;
  int i = 0;
  int answer = 0;
  while(true) {
    set<char> s;
    while(s.size() < 3 && i < a.size()) {
      s.insert(a[i]);
      ++ i;
    }
    while(true){
      if( i == a.size() ) break;
      s.insert(a[i]);
      if( s.size() > 3 ) break;
      ++ i;
      if( i == a.size() ) break;
    }
    //print_set(s);

    if( s.size() > 0 ) {
      ++ answer;
    }
    if( i == a.size() ) break;
    
  }
  cout << answer << endl;
}
