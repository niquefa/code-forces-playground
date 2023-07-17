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
    int x, a, b, c;
    cin >> x >> a >> b >> c;
    int doors[] = {-1, a, b, c};
    int door_with_no_key = 1;
    if( b == 0 )
      door_with_no_key = 2;
    else if( c == 0 )
      door_with_no_key = 3;
    cout << ( x == door_with_no_key || doors[x] == door_with_no_key? "NO" : "YES") << endl;
  }
  return 0;
}
