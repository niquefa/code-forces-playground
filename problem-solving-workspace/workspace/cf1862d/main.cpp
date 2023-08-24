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
long long nck[500][500];
long long nCk( const int& n , const int& k ){if( k == 0 || k == n )return 1;if( k < 0 || k > n )return 0; if( nck[n][k] != -1 ) return nck[n][k];return nck[n][k] = nCk( n-1 , k ) + nCk( n-1 , k-1 );}
template<class T> long long factorial( const T& n /*hasta 20*/ ){long long f = 1L;for( long long i = 2; i <= n ;++ i )f *= (long long)i;return f;}
long long icecreams(long long k) {
    return (k * (k + 3)) / 2;
}

void solve() {
    long long n;
    cin >> n;
    
    long long lo = 1, hi = 99999999999999ll; // setting a sufficiently large upper bound
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (icecreams(mid) < n) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    
    cout << lo << "\n";
}

