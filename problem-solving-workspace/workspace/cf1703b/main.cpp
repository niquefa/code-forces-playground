#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <inttypes.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

const int MAX = 28;
int a[MAX];
bool already_solved[MAX];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int test_count, n, ans, index;
  cin >> test_count;
  for( int test = 0; test < test_count; ++test ) {
    cin >> n;
    string s;
    cin >> s;
    memset(a, 0, sizeof(a));
    memset(already_solved, false, sizeof(already_solved));
    ans = 0;
    for( int i = 0; i < n; ++i ) {
      index = s[i] - 'A';
      if( !already_solved[index]) {
        already_solved[index] = true;
        ++ ans;
      }
      ++ans;
    }
    cout << ans << endl;
  }

  return 0;
}