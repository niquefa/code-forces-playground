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

int last_element_equal_or_lower(const std::vector<long long>& vec, long long element) {
    auto it = std::upper_bound(vec.begin(), vec.end(), element);
    if (!vec.empty() && it != vec.begin()) {
        return std::distance(vec.begin(), --it);
    } else {
        return -1;
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  vector<long long> all_ordinary_numbers;
  for( int digit = 1; digit <= 9; ++ digit ) {
    long long current_number = digit;
    while(true) {
      all_ordinary_numbers.push_back(current_number);
      if( current_number > 1000000000 ) break;
      current_number = current_number * 10 + digit;
    }
  }
  debug(all_ordinary_numbers.size());
  sort(all_ordinary_numbers.begin(), all_ordinary_numbers.end());
  for( int test = 0; test < test_cases; ++ test ) {
    int n;
    cin >> n;
    int index = last_element_equal_or_lower(all_ordinary_numbers, n);
    cout << index + 1 << endl;
  }
  return 0;
}