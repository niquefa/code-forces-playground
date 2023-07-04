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
    int test_cases;
    cin >> test_cases;
    for( int test = 0; test < test_cases; ++ test ) {
      string s;
      cin >> s;
      if( s.size() % 2 == 1 ) {
        cout << "NO" << endl;
        continue;
      }
      bool f = true;
      int half_index = s.size()/2;
      for(int i = 0; f && i < half_index; ++ i )
        f &= s[i] == s[half_index + i];
      cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}

