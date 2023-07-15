#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int current_test = 0; current_test < test_cases; ++ current_test ) {
    long long n, m, x;
    cin >> n >> m >> x;
    int row, col;
    if( x % n == 0 ) {
      row = n;
      col = x / n;
    } else {
      row = x % n;
      col = x / n + 1;
    }
    cout << (row - 1) * m + col << '\n';

  }
  return 0;
}
