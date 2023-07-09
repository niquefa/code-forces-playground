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
  if( n % 2 == 1 ) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> p(n);
  for( int i = 0; i < n; ++i ) p[i] = i+1;
  for( int i = 0; i < n; i += 2 ) swap( p[i], p[i+1] );
  for( int i = 0; i < n; ++i ) cout << p[i] << " ";
  return 0;
}
