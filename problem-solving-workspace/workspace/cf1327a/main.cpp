#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    long long n, k;
    cin >> n >> k;
    if( k == 1 ) {
      cout << (n % 2 == 1 ? "YES" : "NO") << endl;
      continue;
    }
    if( k*k > n ) {
      cout << "NO" << endl;
      continue;
    }
    if( n % 2 != k % 2 ) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;

  }
  return 0;
}
