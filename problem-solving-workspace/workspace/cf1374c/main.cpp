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
    string s;
    int n;
    cin >> n >> s;
    int balanced = 0;
    int ans = 0;
    
    for( int i = 0; i < s.size(); ++i ) {
      if( s[i] == '(' ) {
        ++balanced;
      } else {
        --balanced;
      }
      if ( balanced < 0 ) {
        balanced = 0;
        ++ans;
      }
    }
    cout << ans << endl;
  }
  return 0;
}