#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a, b, n;
  cin >> n >> a >> b;
  int ans = 0;
  for( int i = 1; i <= n; ++ i )
    if( a + 1 <= i && n-i <= b ) {
      ++ans;
    }
      
  cout << ans << endl;
  return 0;
}
