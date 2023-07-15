#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long a, b;
  cin >> a >> b;
  long long f = 1;
  for( int i = 2; i <= min(a, b); ++ i )
    f *= i;
  cout << f << endl;
  return 0;
}
