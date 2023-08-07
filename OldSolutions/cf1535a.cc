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

template<class T> int find_first( vector< T >& v, T o ){   for( int i = 0; i < v.size(); ++ i )if( v[i] == o )return i; return -1;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test_cases;
    cin >> test_cases;
    for( int test = 0; test < test_cases; ++ test ) {
      vector<int> a(4);
      cin >> a[0] >> a[1] >> a[2] >> a[3];
      vector<int> original(a.begin(), a.end());
      sort(a.begin(), a.end());
      int x = find_first(a,original[2]);
      int y = find_first(a,original[3]);
      bool f = ( x <= 1 && y >= 2 ) || (y <= 1 && x >= 2);
      cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}

