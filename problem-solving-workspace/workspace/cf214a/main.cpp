#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n , m, answer = 0;
  cin >> n >> m;
  for( int i = 0; i <= n; ++ i ) {
    for( int j = 0; j <= m; ++ j ) {
      if(i*i +j != n) continue;
      if(i + j*j != m) continue;
      answer ++;
    }
  }
  cout << answer << endl;
  return 0;
}
