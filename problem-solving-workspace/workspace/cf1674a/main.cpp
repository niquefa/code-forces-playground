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
template<class T> inline T sqr (T b){return(b*b);}

template<class T,class E> T fpow( T b , E e){if(e<0) return 1/fpow(b,-e);if(e==0)return 1;else if(e%2==0)return sqr(fpow(b,e/2));else return b*fpow(b,e-1);}

void solve() {
  long long x, y;
  cin >> x >> y;
  if( x == y ) {
    cout << 1 << " " << 1 << endl;
    return;
  }
  if( y < x ) {
    cout << 0 << " " << 0 << endl;
    return;
  }
  for( long long a = 1; a < 60; a++ ) {
    for( long long b = 1; ; b++ ) {
      long long r = x * fpow(b,a);
      //debug(x,y,a,b,r);
      if( r > 10e9 || r > y) break;
      if( r == y ) {
        cout << a << " " << b << endl;
        return;
      }
    }
  }
  cout << 0 << " " << 0 << endl;
}
