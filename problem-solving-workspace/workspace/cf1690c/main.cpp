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
int s[MAX];
int f[MAX];

bool already_solved[MAX];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int test_count, n;
  cin >> test_count;
  for( int test = 0; test < test_count; ++test ) {
    cin >> n;
    for( int i = 0; i < n; ++i )
      cin >> s[i];
    for( int i = 0; i < n; ++i )
      cin >> f[i];

    cout << f[0]-s[0];

    for( int i = 1; i < n; ++i ) {
      if( s[i] > f[i-1]) {
        cout << " " << f[i]-s[i];
      } else {
        cout << " " << f[i]-f[i-1];
      }
    }
    
    cout << endl;
  }

  return 0;
}