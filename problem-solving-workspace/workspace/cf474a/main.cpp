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

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string direction, message;
  cin >> direction >> message;
  string k[3];
  k[0] = "qwertyuiop";
  k[1] = "asdfghjkl;";
  k[2] = "zxcvbnm,./";
  map<char, char> left, right;
  for( auto line : k) {
    for( auto i = 1; i < line.size(); ++ i )
      right[line[i]] = line[i-1];      
    for( auto i = 0; i < line.size() - 1; ++ i )
      left[line[i]] = line[i+1];      
  }
  for( auto c : message ) {
    if( direction == "R" )
      cout << right[c];
    else
      cout << left[c];
  }
  return 0;
}