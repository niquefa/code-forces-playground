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

const int MAX = 100002;
int a[MAX];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n ,t;
  cin >> n >> t;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  int right_index = 0;
  int current_sum = 0;
  int longest_sub_array_length = 0;
  for ( int left_index = 0; left_index < n; ++ left_index ) {
    while( right_index < n && current_sum + a[right_index] <= t ) {
      current_sum += a[right_index];
      ++ right_index;
    }
    longest_sub_array_length = max( longest_sub_array_length , right_index - left_index );
    current_sum -= a[left_index];
  }
  cout << longest_sub_array_length << endl;
  return 0;
}