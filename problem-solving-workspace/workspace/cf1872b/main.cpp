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
    //cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}


void solve() {
  int num_of_traps;
  cin >> num_of_traps;

  vector<pair<int, int>> traps(num_of_traps);
  for(int i = 0; i < num_of_traps; ++i) 
    cin >> traps[i].first >> traps[i].second;
  
  sort(traps.begin(), traps.end());

  for(int k = 402; k >= 1; --k) {
    bool is_safe = true;

    for(const auto& trap : traps) {
      long long di = trap.first;
      long long si = trap.second;

      long long activation_time = di - 1 + si;
      long long return_cross_time = 2 * k - di;

      if(return_cross_time > activation_time) {
        is_safe = false;
        break;
      }
    }


    if(is_safe) {
      cout << k << '\n';
      return;
    }
  }
  cout << 1 << '\n';
}
