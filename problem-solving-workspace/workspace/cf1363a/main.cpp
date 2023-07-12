#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n, x;
    cin >> n >> x;
    int odd = 0, even = 0;
    for( int i = 0; i < n; ++ i) {
      int tmp;
      cin >> tmp;
      odd += tmp % 2 == 1;
      even += tmp % 2 == 0;
    }
    if( odd == 0 ) {
      cout << "No" << endl;
      continue;
    }
    --odd;
    --x;
    while( odd >= 2 && x >= 2 ) {
      odd -= 2;
      x -= 2;
    }
    cout << (even >=x ? "Yes" : "No") << endl;
  }
  return 0;
}
