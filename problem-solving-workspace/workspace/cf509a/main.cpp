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

long long f( int i, int j ) {
  if( i == 1 ) return 1;
  if( j == 1 ) return 1;
  return f( i - 1, j ) + f( i, j - 1 );
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  cout << f( n, n ) << endl;
  return 0;
}
