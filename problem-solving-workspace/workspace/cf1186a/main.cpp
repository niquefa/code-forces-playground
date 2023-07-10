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
  int n , m , k;
  cin >> n >> m >> k;
  cout << ( m >= n && k >= n ? "Yes" : "No") << endl;
  return 0;
}
