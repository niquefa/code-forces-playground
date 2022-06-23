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
const int MAX = 500001;
long long a[MAX];
long long s[MAX]; //s[i] : sum a_0 + a_1 + .... + a_i
long long t[MAX]; //t[i] : count of: Positions in which s[i] == 2/3 s[n-1], for [i,n-1]
int n;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin >> n;
  long long zero_count = 0;
  for( int i = 0; i < n; ++i  ) {
    cin >> a[i];
    s[i] = i == 0 ? a[0] : a[i]+s[i-1];
    zero_count += s[i] == 0 ? 1 : 0;
  }
  if( abs(s[n-1]) % 3 != 0 || n < 3 ) {
    cout << "0" << endl;
    return 0;
  }
  //Special case when the sum of all elements is zero.
  if( s[n-1] == 0 ) {
    cout << ((zero_count-2LL)*(zero_count-1LL)/2LL) << endl; 
    return 0;
  }

  long long a_third = s[n-1] / 3;
  long long two_thirds = 2 * s[n-1] / 3;

  t[n-1] = s[n-1] == two_thirds ? 1 : 0;
  for( int i = n-2; i >= 0 ; --i )
    t[i] = t[i+1] + (s[i] == two_thirds ? 1 : 0);

  
  long long ans = 0;
  for( int i = 0; i < n-2; ++ i ) 
    ans += s[i] == a_third ? t[i+1] : 0;

  cout << ans << endl;
  return 0;
}