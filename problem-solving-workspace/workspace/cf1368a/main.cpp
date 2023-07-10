#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int a, b, n;
    cin >> a >> b >> n;
    int ans = 0;
    long long current_sum = 0;
    long long big = max(a,b);
    long long small = min(a,b);
    long long new_big, new_small;
    while(true) {
      new_big = max(big,small);
      new_small = min(big,small);
      new_small += new_big;
      big = new_big;
      small = new_small;
      ++ans;
      if( big > n || small > n ) break;
    }
    cout << ans << endl;
  }
  return 0;
}
