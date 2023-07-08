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


#define rsor(x)          std::sort((x).rbegin(),(x).rend());
int fabs(int a) { return a < 0 ? -a : a; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int k, n;
    cin >> n >> k;
    vector<int> v(n,0);
    for( int i = 0; i < n; ++ i ) cin >> v[i];
    
    if( n == k ) {
      cout << 0 << endl;
      continue;
    }
    int ans = 0;
    vector<int> d;
    for( int i = 1; i < n; ++ i ) 
      d.push_back(fabs(v[i] - v[i-1]));
    
    rsor(d);
    for( int i = k-1; i < n-1; ++ i ) 
      ans += d[i];
    
    cout << ans << endl;
  }
  return 0;
}