#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int a, b;
    cin >> a >> b;
    if( a > 1 ) {
      cout << 1 << endl;
      continue;
    }
    cout << 2*(b+1) << endl;
  }
  return 0;
}
