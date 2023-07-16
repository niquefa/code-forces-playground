#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int get_s( int x ) {
  int ans = 0;
  while(x > 0) {
    ans += x % 10;
    x /= 10;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // set<int> interesting;
  // int prev_sum = 9;
  // for( int i = 10, s; i <= 10000; ++ i ) {

  //   s = get_s(i);
  //   if( s <= prev_sum ) {
  //     interesting.insert(i-1);
  //     cout << i-1 << " " << interesting.size() << endl;
  //   }
  //   prev_sum = s;
    
  // }
  // for( auto i : interesting ) cout << i << endl;
  // cout << endl;
  // cout << interesting.size() << endl;
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    int n;
    cin >> n;
    int last_digit = n % 10;
    if( last_digit == 9 ) {
      cout << n / 10 + 1 << endl;
    } else {
      cout << n / 10 << endl;
    }
  }
  return 0;
}
