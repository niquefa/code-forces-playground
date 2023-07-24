#include <bits/stdc++.h>
using namespace std;

void solve() {
  bool R = false;
  vector<string> m;
  for( int i = 0; i < 8; ++ i ) {
    string s;
    cin >> s; 
    if( s == "RRRRRRRR")
      R = true;
  }

  cout << (R ? "R" : "B") << endl;
}

int main() {
  auto start_execution_time = std::chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = std::chrono::high_resolution_clock::now();

  chrono::duration<double, std::milli> elapsed = start_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
