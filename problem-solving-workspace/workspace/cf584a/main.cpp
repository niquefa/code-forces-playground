#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>
#include <sstream>
#include <utility>
#include <cctype>
#include <numeric>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <limits>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <functional>
#include <inttypes.h>
#include <fstream>
using namespace std;
template<class T> string tostring(T x) {ostringstream sout;sout<<x;return sout.str();}
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

string get_answer( int ans, int n ){
  string s = to_string(ans);
  while( s.size() < n ) 
    s = '1' + s;
  return s;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for( long long i = 0; i < 1000; ++ i ){
    debug(2520*i);
  }
  int n, t;
  cin >> n >> t;
  if( n == 1 ) {
    cout << ( t == 10 ? -1 : t) << endl;
    return 0;
  }
  if( t == 10 ) {
    cout << get_answer(10, n) << endl;
    return 0;
  }
  for( int i = 0; i < n; ++ i ) {
    cout << t;
  }
  cout << endl;
  return 0;
}