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
  int n, m;
  cin >> n >> m;
  debug(n, m);
  if( m == 1 ) {
    cout << 0 << endl;
    for( int i = 0; i < n; ++ i ) 
      cout << 0 << endl;
    return;
  }

  vector<int> permutation(m);
  iota(permutation.begin(), permutation.end(), 0);

  random_device rd;
  mt19937 g(rd());
  if( n == 1 ) {
    cout << 2 << endl;
  } else { 
    long long b = 0;
    for( int i = 0; i < n-2; ++ i ) 
      b += i;
    cout << b <<endl; 
  }
  
  for(int i = 0; i < n; ++i) {
    shuffle(permutation.begin(), permutation.end(), g);

    for(int j = 0; j < m; ++j) {
      while(permutation[j] == j) {
        shuffle(permutation.begin(), permutation.end(), g);
      }
    }
    for(int j = 0; j < m; ++j) {
      cout << permutation[j] << " ";
      
    }
    cout << "\n";
  }
}
