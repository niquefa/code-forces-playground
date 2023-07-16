#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int current_test = 0; current_test < test_cases; ++ current_test ) {
    int n, m, k, x, y, xv, yv;
    cin >> n >> m >> k >> xv >> yv;
    int parity_v = (xv + yv) % 2;
    set<int> parity_f;
    for( int i = 0; i < k; ++ i) {
      cin >> x >> y;
      parity_f.insert((x + y) % 2);
    };
    if( parity_f.size() == 1 && parity_f.count(parity_v) == 0 ) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    
  }
  return 0;
}
