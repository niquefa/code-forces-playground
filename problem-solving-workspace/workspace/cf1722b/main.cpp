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
    string a , b;
    cin >> a >> b;
    bool ok = true;
    for( int i = 0; ok && i < n; ++ i ) {
      if( a[i] == 'R' && b[i] != 'R' ) ok = false;
      if( b[i] == 'R' && a[i] != 'R' ) ok = false;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}