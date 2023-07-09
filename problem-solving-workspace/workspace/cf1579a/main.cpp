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

#define countx(c,x)      std::count((c).begin(),(c).end(),x)
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    string s;
    cin >> s;
    cout << (countx(s,'A') + countx(s,'C') == countx(s,'B') ? "YES" : "NO") << endl;
  }
  return 0;
}
