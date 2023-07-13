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
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n;
    cin >> n;
    n -= 3;

    int h3 = n / 3;
    int h2 = h3 + 1;
    int h1 = h3 + 2;
    if( n % 3 == 1 ) 
      ++h1;
    if( n % 3 == 2 ) 
      ++h1, ++h2;

    cout << h2 << " " << h1 << " " << h3 << endl;
  }
  return 0;
}
