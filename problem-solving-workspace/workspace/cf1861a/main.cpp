#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


#define ones(n)          __builtin_popcount(n)
const int MAX = 1001;
bool used[MAX];
bool is_prime[MAX];

void fill_primes() {
  memset(is_prime, true, sizeof(is_prime));

  is_prime[0] = is_prime[1] = false;

  for(int i = 2; i * i < MAX; i++) {
    if(is_prime[i]) {
      for(int j = i * i; j < MAX; j += i) {
        is_prime[j] = false;
      }
    }
  }
}
void solve();
int main() {
  auto start_execution_time = chrono::high_resolution_clock::now();
  fill_primes();
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
template<class T> string tostring(T x) {ostringstream sout;sout<<x;return sout.str();}

template<class T> int toint( T s ) {int v;istringstream sin( tostring(s) );sin>>v;return v;}

void solve() {
  string sn;
  cin >> sn;
  int n = sn.size();
  int num = toint(sn);
  int index9 = 0;
  int index7 = 0;
  for( int i = 0;i < n; ++ i ) {
    if( sn[i] == '9' ) index9 = i;
    if( sn[i] == '7' ) index7 = i;
  }
  if( index7 < index9 ) {
    cout << 79 << endl;
  } else {
    cout << 97 << endl;
  }

}
