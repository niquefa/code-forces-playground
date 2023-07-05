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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int h , m;
    cin >> h >> m;
    int ans = 0;
    while( h != 0 || m != 0 ) {
      ++ ans;
      ++ m;
      if( m == 60 ) {
        m = 0;
        ++ h;
      }
      if ( h == 24 )
        break;
    }
    cout << ans << endl;
  }
  return 0;
}