#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define swapd(a,b)       (((a)^=(b)),((b)^=(a)),((a)^=(b)));
bool is_arithmetic_progression( const int& a, const int& b, const int& c ) {
  return b - a == c - b;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    long long a, b, c;
    cin >> a >> b >> c;
    if( is_arithmetic_progression(a, b, c) ) {
      cout << "YES" << endl;
      continue;
    }
    int new_a = b - (c - b);
    if(new_a >= a && new_a % a == 0 && new_a != 0) {
        cout << "YES" << endl;
        continue;
    }

    int new_b = a + (c - a)/2;
    if(new_b >= b && (c-a)%2 == 0 && new_b % b == 0 && new_b != 0) {
        cout << "YES" << endl;
        continue;
    }

    int new_c = a + 2*(b - a);
    if(new_c >= c && new_c % c == 0 && new_c != 0) {
        cout << "YES" << endl;
        continue;
    }

    cout << "NO" << endl;
  }
  return 0;
}
