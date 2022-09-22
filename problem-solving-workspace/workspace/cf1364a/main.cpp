#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <inttypes.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

const int MAX = 100001;
int a[MAX];
long long prefix_sum[MAX];
long long suffix_sum[MAX];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int test_count, n, x;
  cin >> test_count;
  for( int test = 0; test < test_count; ++test ) {
    cin >> n >> x;
    int ans = 0;
    long long sum = 0;
    bool always_divisible_by_n = true;
    for( int i = 0; i < n; ++i ) {
      cin >> a[i];
      sum += a[i];
      always_divisible_by_n &= a[i]%x == 0;
    }
    if( always_divisible_by_n )
    {
      cout << "-1" << endl;
      continue;
    }      
    if( sum % x != 0 ) {
      cout << n << endl;
      continue;
    }

    int removing_to_left = 0;
    for( int i = 0; i < n; ++i ) {
      removing_to_left++;
      if( a[i] % x != 0 ) 
        break;
    }

    int removing_to_right = 0;
    for( int i = n-1; i >= 0; --i ) {
      removing_to_right++;
      if( a[i] % x != 0 ) 
        break;
    }
        
    //cout << removing_to_left << " vs " << removing_to_right << endl;

    cout << n-min(removing_to_left, removing_to_right) << endl;
  }

  return 0;
}