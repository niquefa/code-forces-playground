#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n, k;
    cin >> n >> k;
    if( n == k ) {
      cout << 1 << endl;
      continue;
    }
    if( n < k ) {
      cout << (k/n + (k%n > 0 ? 1 : 0)) << endl;
      continue;
    }
    cout << (n%k == 0 ? 1: 2) << endl;
  }
  return 0;
}
