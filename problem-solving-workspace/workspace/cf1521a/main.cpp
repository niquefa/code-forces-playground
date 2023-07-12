#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    long long a, b, x, y, z;
    cin >> a >> b;
    if( b == 1 ) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    x = a*(b-1);
    y = a*(b+1);
    z = x+y;
    cout << x << " " << y << " " << z << endl;
  }
  return 0;
}
