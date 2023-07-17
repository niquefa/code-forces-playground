#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

bool has_only_odd_digits( int n ) {
  while(n > 0) {
    if( (n % 10) % 2 == 0 ) return false;
    n /= 10;
  }
  return true;
}

template<class T> string tostring(T x) {ostringstream sout;sout<<x;return sout.str();}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    int n;
    cin >> n;
    if( has_only_odd_digits(n) ) {
      cout << -1 << endl;
      continue;
    }
    if( n%2 == 0 ) {
      cout << 0 << endl;
      continue;
    }
    int first_digit = tostring(n)[0] - '0';
    debug(n, first_digit);
    if( first_digit % 2 == 0 ) {
      cout << 1 << endl;
      continue;
    }
    cout << 2 << endl;
  }
  return 0;
}
