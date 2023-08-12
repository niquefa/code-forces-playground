#include <bits/stdc++.h>
using namespace std;

void solve();
int main() {
  auto start_execution_time = chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  //cin >> test_cases;
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
  int pages;
  cin >> pages;
  vector<int> pages_per_day_of_the_week(7);
  for( int i = 0; i < 7; ++ i) cin >> pages_per_day_of_the_week[i];
  
  int current_day = 0;
  while( pages > 0 ) {
    pages -= pages_per_day_of_the_week[current_day];
    if( pages <= 0) break;
    current_day = (current_day + 1) % 7;
  }
  cout << current_day+1 << endl;
}
