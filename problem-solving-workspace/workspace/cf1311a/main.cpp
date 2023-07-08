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
    int a, b;
    cin >> a >> b;
    if( a == b ) {
      cout << "0" << endl;
    } else if( ( b > a &&  (b-a)%2 == 1) || ( a > b && (a-b)%2==0) ) {
      cout << "1" << endl;
    } else {
      cout << "2" << endl;
    }
  }
  return 0;
}