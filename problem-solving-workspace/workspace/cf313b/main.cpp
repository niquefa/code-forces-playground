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
// DP SubArraySum
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  string s;
  cin >> s;
  int m;
  cin >> m;
  int n = s.size();
  vector<int> a(n, 0);
  for( int i = 1; i < n; ++ i )
    a[i] = s[i] == s[i-1] ? 1 : 0;

  vector<int> sum(n, 0);
  sum[0] = a[0];
  for( int i = 1; i < n; ++ i )
    sum[i] = sum[i-1] + a[i];

  for( int i = 0; i < m ; ++ i ) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    cout << sum[r] - sum[l] << endl;
  }


  return 0;
}