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
    
  vector<int> x(2);
  vector<int> y(2);
  cin >> x[0] >> y[0] >> x[1] >> y[1];
  int dx = abs(x[0] - x[1]);
  int dy = abs(y[0] - y[1]);
  if( dx == 0 ) {
    int nx = x[0] + dy;
    cout << nx << " " << y[0] << " " << nx << " " << y[1] << endl;
    return 0;
  }
  if( dy == 0 ) {
    int ny = y[0] + dx;
    cout << x[0] << " " << ny << " " << x[1] << " " << ny << endl;
    return 0;
  }
  if( dx != dy ) {
    cout << -1 << endl;
    return 0;
  }
  cout << x[0] << " " << y[1] << " " << x[1] << " " << y[0] << endl;

  return 0;
}
