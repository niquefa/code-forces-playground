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
  long long n = 0;
  m[40] = 1456789;
  m[41] = 2456789;
  m[42] = 3456789;
  m[43] = 13456789;
  m[44] = 23456789;
  m[45] = 123456789;
  while( m.size() <= 44 ) {
    ++n;
    if( !decide_if_all_digits_are_distinct(n) )
      continue;
    int sum_of_digits_in_n = get_sum_of_digits(n);
    if( m.count(sum_of_digits_in_n) )
      continue;
    m[sum_of_digits_in_n] = n;
    debug(n, sum_of_digits_in_n);
  }
//  for( auto it = m.begin(); it != m.end(); ++ it ) 
//    cout << " m[" << it->second << "] = " << it->first << ";" << endl;
  
  int test_cases;
  cin >> test_cases;
  
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    int s;
    cin >> s;
    cout << m[s] << endl;
  }
  return 0;
}
