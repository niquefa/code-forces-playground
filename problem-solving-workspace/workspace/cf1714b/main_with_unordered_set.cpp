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

const int MAX = 200001;

int a[MAX];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int test_count, n, remove;
  cin >> test_count;
  for( int test = 0; test < test_count; ++test ) {
    cin >> n;
    unordered_set<int> v;
    for( int i = 0; i < n; ++i )
      cin >> a[i];
    remove = 0;
    for( int i = n-1; i >= 0; --i ) {
      if( v.find(a[i]) != v.end() )
        break;
      ++ remove;
      v.insert(a[i]);
    }

    cout << n-remove << endl;
  }

  return 0;
}