#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int current_test = 0; current_test < test_cases; ++ current_test ) {
    int n;
    cin >> n;
    if( n == 1 ) {
      cout << -1 << endl;
      continue;
    }
    cout << 2;
    for( int i = 0; i < n-1; ++ i )
      cout << 3;
    cout << endl;
  }
  return 0;
}
