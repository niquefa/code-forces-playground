#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long option2 = abs(b-c) + c;
    if( option2 == a ) {
      cout << 3 << endl;
    } else if( option2 < a ) {
      cout << 2 << endl;
    } else {
      cout << 1 << endl;
    }
  }
  return 0;
}
