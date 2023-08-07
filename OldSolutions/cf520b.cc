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

#define mone(a)          memset(a,-1,sizeof(a));
const int oo = 1<<25;
const int MAX = 200100;
const int MAX_M = 20002;
int dp[MAX];
int n, m;
int f(int k) {
  if ( k <= 0 || k > MAX_M ) return oo;
  if ( k == m )
    return 0;
  int &ans = dp[k];

  if ( ans != -1 ) return ans;
  ans = oo;
  ans = 1 + min(f(k-1), f(k*2));
  return ans;
}
int main() {
  cin >> n >> m;
  mone(dp);
  cout << f(n) << endl;
}

