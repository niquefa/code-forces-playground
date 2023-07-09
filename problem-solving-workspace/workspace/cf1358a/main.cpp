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

long long solve(int n , int m) {
  long long answer = 0;
  long long d = n/2;
  long long r = n%2;
  
  answer += d*m;
  if( r > 0 ) {
    answer += m/2;
    if( m%2 == 1 ) answer += 1;
  }
  return answer;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n, m;
    cin >> n >> m;
    cout << max(solve(n,m), solve(m,n)) << endl;
  }
  return 0;
}
