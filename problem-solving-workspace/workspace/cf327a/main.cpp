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

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<bool> v(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    v[i] = x == 1;
  }
  int ans = 0;
  for( int i = 0; i < n; ++ i ) {
    for( int j = i; j < n; ++ j ) {
      int candidate = 0;
      for( int k = i; k <= j; ++ k )
        candidate += !v[k] ? 1 : 0;
      for( int k = 0; k < i; ++ k )
        candidate += v[k] ? 1 : 0;
      for( int k = j+1; k < n; ++ k )
        candidate += v[k] ? 1 : 0;
      ans = max( ans, candidate );
    }
  }
  cout << ans << endl;
  return 0;
}