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
  int n;
  cin >> n;
  vector<int> a(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];
  int ans = 0;
  int current_increase = 0;
  for( int i = 1; i < n; ++ i ) {
    if(a[i] > a[i-1]) {
      current_increase ++;
      ans = max(ans, current_increase);
    } else {
      current_increase = 0;
    }
  }
  cout << ans + 1;
  return 0;
}
