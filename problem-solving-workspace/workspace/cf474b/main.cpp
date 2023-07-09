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

int last_element_equal_or_lower(const std::vector<int>& vec, int element) {
    auto it = std::upper_bound(vec.begin(), vec.end(), element);
    if (!vec.empty() && it != vec.begin()) {
        return std::distance(vec.begin(), --it);
    } else {
        return -1;
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) cin >> b[i];
  vector<int> to(n);
  int current_id = 1;
  for( int i = 0; i < n; ++ i ) {
    to[i] = current_id + a[i]-1;
    current_id = to[i] + 1;
  }
  for( int i = 0; i < m; ++ i ) {
    int index_found = last_element_equal_or_lower( to, b[i] );
    cout << (b[i] == to[index_found] ? index_found + 1 : index_found + 2) << endl;
  }
  
  return 0;
}