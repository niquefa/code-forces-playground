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
  string x;
  cin >> x;
  for( int i = 0; i < x.size(); ++ i ) {
    int a = x[i] - '0';
    int b = 9-a;
    if( b == 0 && i == 0) b = a;
    cout << min(a,b);
  }

  return 0;
}
