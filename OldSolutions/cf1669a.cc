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

//g++ hello.cc && ./a.out < t.in
int main() {
    int test_cases, r;
    cin >> test_cases;
    for( int test = 0; test < test_cases; ++ test ) {
      cin >> r;
      cout << "Division ";
      if( 1900 <= r ) {
        cout << "1\n";
      } else if (1600 <= r && r <= 1899) {
        cout << "2\n";
      } else if (1400 <= r && r <= 1599) {
        cout << "3\n";
      } else if (r <= 1399) {
        cout << "4\n";
      }
    }
    return 0;
}

