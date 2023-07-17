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
  int n, m;
  cin >> n >> m;
  int max_turns = 0;
  vector<int> a(n);
  for( int i = 0; i < n; ++ i ) cin >> a[i];

  for( int i = 0; i < n; ++ i )
    max_turns = max( max_turns, a[i]/m + (a[i]%m != 0) );
  for( int i = n-1; i >= 0; --i )
    if( a[i]/m + (a[i]%m != 0) == max_turns ) {
      cout << (i+1) << endl;
      break;
    }
  return 0;
}
