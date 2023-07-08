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
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    vector<int> a(3);
    int n;
    cin >> a[0] >> a[1] >> a[2] >> n;
    sort(a.begin(), a.end());
    int remain = a[2] - a[0] + a[2] - a[1];
    if( n >= remain && (n - remain) % 3 == 0 ) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}