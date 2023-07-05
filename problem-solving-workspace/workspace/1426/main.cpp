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
    vector<int> a(2002, 0);
    int n, x;
    cin >> n >> x;
    a[1] = a[2] = 1;

    for( int i = 3, f = 2; i <= n; i += x, ++f ){
      for( int j = i; j < i + x && j <= n; ++j ){
        a[j] = f;
      }
    }
    cout << a[n] << endl;
  }
  return 0;
}