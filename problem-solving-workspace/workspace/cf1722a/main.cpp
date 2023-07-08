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
  string timur = "Timur";
  sort(timur.begin(), timur.end());
  for( int test = 0; test < test_cases; ++ test ) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if( s == timur ) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}