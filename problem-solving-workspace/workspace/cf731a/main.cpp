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

const string a = "abcdefghijklmnopqrstuvwxyz";

int get_distance( char begin, char end ) {
  int index = begin - 'a';
  int ans = 0;
  int going_up = index;
  int going_down = index;
  int current_char = begin;
  while(true) {
    if( a[going_up] == end || a[going_down] == end) break;
    ++ ans;
    going_up++;
    if( going_up == a.size() ) going_up = 0;
    going_down--;
    if( going_down == -1 ) going_down = a.size() - 1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  while( cin >> s ) {
    int ans = 0;
    s = 'a' + s;
    for( int i = 1; i < s.size(); ++i ) {
      int distance = get_distance( s[i-1], s[i] );
      ans += distance;
    }
    cout << ans << endl;
  }
  return 0;
}