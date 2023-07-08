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
    int max = 1, w, h, n;
    cin >> w >> h >> n;
    while( true ) {
      if( w % 2 == 0 ) {
        w /= 2;
        max *= 2;
      } else if( h % 2 == 0 ) {
        h /= 2;
        max *= 2;
      } else {
        break;
      }
    }
    cout << (max >= n ? "YES" : "NO") << endl;
  }
  return 0;
}