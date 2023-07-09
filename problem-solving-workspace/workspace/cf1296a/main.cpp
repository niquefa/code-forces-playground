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
    int n;
    cin >> n;
    int tmp;
    bool even_found = false;
    bool odd_found = false;
    for( int i = 0; i < n; ++ i) {
      cin >> tmp;
      even_found |= (tmp % 2 == 0);
      odd_found |= (tmp % 2 == 1);
    } 
    if( n == 1 ){
      cout << (odd_found ? "YES" : "NO") << endl;
      continue;
    }
    if( even_found && odd_found ) {
      cout << "YES" << endl;
      continue;
    }
    if( !odd_found ) {
      cout << "NO" << endl;
      continue;
    }
    cout << (n%2==1 ? "YES" : "NO") << endl;
  }
  return 0;
}