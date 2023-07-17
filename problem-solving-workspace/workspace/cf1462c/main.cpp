#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int get_sum_of_digits( long long n ) {
  int ans = 0;
  while( n ) {
    ans += n % 10;
    n /= 10;
  }
  return ans;
}
bool decide_if_all_digits_are_distinct( long long n ) {
  set<int> s;
  while( n ) {
    int digit = n % 10;
    if( s.count(digit) ) return false;
    s.insert(digit);
    n /= 10;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  map<int,int> m;
  for( long long n = 1; n <= 9876543210LL; ++ n ) {
    if( m.size() >= 42 ) break;

    int sum_of_digits_in_n = get_sum_of_digits(n);

    if( m.count(sum_of_digits_in_n) ) continue;

    bool all_digits_are_distinct = decide_if_all_digits_are_distinct(n);

    if( all_digits_are_distinct ) {
      m[sum_of_digits_in_n] = n;
      debug(n, sum_of_digits_in_n, all_digits_are_distinct);
    }
  }


  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    int x;
    cin >> x;
    if( x >= 46 ) {
      cout << -1 << endl;
      continue;
    }
    if( x == 45 ) {
      cout << 123456789LL << endl;
      continue;
    }
    if( x == 44 ) {
      cout << 23456789LL << endl;
      continue;
    }
    if( x == 43 ) {
      cout << 13456789LL << endl;
      continue;
    }
    if( x == 42 ) {
      cout << 3456789LL << endl;
      continue;
    }
    cout << m[x] << endl;
  }
  return 0;
}
