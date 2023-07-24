#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve() {
  long long a, b, k;
  cin >> a >> b >> k;
  long long x = (k/2)*(a-b);
  if( k % 2 == 1 ) 
    x += a;
  cout << x << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  return 0;
}
