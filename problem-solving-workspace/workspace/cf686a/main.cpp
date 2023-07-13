#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, x, t, d = 0;
  string s;
  cin >> n >> x;
  for( int i = 0; i < n; ++ i ) {
    cin >> s >> t;
    if( s == "+" ) x += t;
    else {
      if( x >= t ) x -= t;
      else d++;
    }
  }
  cout << x << " " << d << endl;
  return 0;
}
