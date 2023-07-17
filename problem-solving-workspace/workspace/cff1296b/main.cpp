#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    long long current_cash;
    cin >> current_cash;
    long long total_expended = current_cash;
    do{
      long long cash_back = current_cash/10;
      long long cash_remainder = current_cash%10;
      total_expended += cash_back;
      current_cash = cash_back + cash_remainder;
      if( cash_back == 0 )break;
    } while( true );

    cout << total_expended << endl;
  }
  return 0;
}
