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

template<class T>
inline void squeeze(vector <pair <T, int> > &M, T &n, T p) {
  int C = 0;
  for (; n % p == 0; n /= p) ++C;
  if (C != 0) M.push_back(make_pair(p, C));
}
template<class T> inline vector <pair <T, int> > factorize(T n) {
  if (n < 0) return factorize(-n);
  vector <pair <T, int> > M;
  if (n < 2) return M;
  squeeze(M, n, (T) 2);
  squeeze(M, n, (T) 3);
  T p = 5;
  while (n > 1) {
    squeeze(M, n, p);
    squeeze(M, n, p + 2);
    p += 6;
    if (p * p > n) p = n;
  }
  return M;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n;
    cin >> n;
    if( n == 1 ){
      cout << 0 << endl;
      continue;
    }
    vector<pair<int,int> > f = factorize(n);
    debug("For", n);
    debug(f.size());
    map<int,int> m;
    m[2] = 0;
    m[3] = 0;
    bool no_solution = false;
    for(int i = 0; i < f.size(); ++ i ){
      debug(f[i].first, f[i].second);
      m[f[i].first] = f[i].second;
      if (f[i].first != 2 && f[i].first != 3) {
        cout << -1 << endl;
        no_solution = true;
        break;
      }
    }
    if( no_solution ) continue;
    sort(f.begin(), f.end());
    if( f.size() == 1 && f[0].first != 2 && f[0].first != 3) {
      cout << -1<< endl;
      continue;
    }
    if( f.size() == 2 && (f[0].first != 2 || f[1].first != 3)) {
      cout << -1 << endl;
      continue;
    }
    if( m[2] > m[3] ) {
      cout << -1 << endl;
      continue;
    }
    cout << 2 * m[3] - m[2] << endl;
  }
  return 0;
}