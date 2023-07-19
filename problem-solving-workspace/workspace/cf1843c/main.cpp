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
    long long n;
    cin >> n;
    long long sum = 0;
    while( n > 0 ) {
      sum += n;
      n /= 2;
    }
    cout << sum << endl;
  }
  return 0;
}
