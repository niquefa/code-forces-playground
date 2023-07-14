#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

template<class T> string tostring(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> int toint( T s ) {int v;istringstream sin( tostring(s) );sin>>v;return v;}
int digit_diff( const int& a, const int& b ) {
  string sa = to_string(a);
  string sb = to_string(b);
  int ans = 0;
  for( auto i = 0; i < sa.size(); ++ i )
    if( sa[i] != sb[i] )
      ++ ans;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n;
    cin >> n;
    if( n % 7 == 0 ) {
      cout << n << endl;
      continue;
    }
    string sn = to_string(n);
    if( sn.size() == 1 ) {
      cout << 7 << endl;
      continue;
    }
    int from = (int)(pow(10, sn.size()-1));
    int to = toint(string(sn.size(), '9'));
    debug(from, to);
    int best_diff = 1000000000;
    int best = -1;
    for( int candidate = from; candidate <= to; ++ candidate) {
      if( candidate % 7 != 0 )
        continue;
      int current_diff = digit_diff(n, candidate);
      if( current_diff < best_diff ) {
        best_diff = current_diff;
        best = candidate;
      }
    }
    cout << best << endl;
  }
  return 0;
}
