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
    int n;
    cin >> n;
    vector<int> a(2*n);
    for( int i = 0; i < 2*n; ++ i ) cin >> a[i];
    int odds = 0;
    for( int i = 0; i < 2*n; ++ i )
      if( a[i] % 2 == 1 ) ++ odds;
    cout << (odds == n ? "Yes" : "No") << endl;
  }
  return 0;
}