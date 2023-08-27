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
  int n, k;
  string s;
  cin >> n >> k >> s;
  if( k%2 == 0 ) {
    sort(s.begin(), s.end());
    cout << s << endl;
    return;
  }
  vector<char> even_positions;
  vector<char> odd_positions;
  for( int i = 0; i < n; ++ i ) {
    if( i % 2 == 0 ) even_positions.push_back(s[i]);
    else odd_positions.push_back(s[i]);
  }
  sort(even_positions.begin(), even_positions.end());
  sort(odd_positions.begin(), odd_positions.end());
  string ss = "";
  for( int i = 0; i < n; ++ i ) {
    if( i % 2 == 0 ) ss += even_positions[i / 2];
    else ss += odd_positions[i / 2];
  }
  cout << ss << endl;
}
