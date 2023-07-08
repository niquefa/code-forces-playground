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
const int ONES = (1<<30)-1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n;
    cin >> n;
    vector<int> v(n);
    int s = ONES;
    for( int i = 0; i < n; ++ i ){
      cin >> v[i];
      s &= v[i];
    }
    int ans = 0;
    int cs = ONES;
    for( int i = 0; i < n; ++ i ){
      cs &= v[i];
      if( cs == 0 ) {
        ++ans;
        cs = ONES;
      }
    }
    cout << max(1,ans) << endl;
  }
  return 0;
}