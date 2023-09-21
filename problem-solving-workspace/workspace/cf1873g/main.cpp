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
const int MAX_N = 200001;
string s;
int cache[MAX_N];

int f(int i) {
    if (i >= s.size() - 1) return 0;
    if (cache[i] != -1) return cache[i];

    int ans = 0;

    if (s[i] == 'B' && s[i + 1] == 'A') {
        ans = max(ans, 1 + f(i + 2)); // Transform the current BA and move on

        // Now, explore transforming every preceding AB
        int j = i - 1;
        int bonus = 0;
        while (j >= 1 && s[j] == 'A' && s[j - 1] == 'B') {
            bonus++;
            j -= 2;
        }
        if (bonus) {
            ans = max(ans, bonus + f(j + 1)); // Transform preceding ABs and then see for the rest
        }
    } else {
        ans = f(i + 1); // Move on without transformation
    }

    return cache[i] = ans;
}


void solve() {
  memset( cache, -1, sizeof cache);
  cin >> s;
  cout << f(0) << endl;
}
  
