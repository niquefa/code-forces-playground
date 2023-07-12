#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int a, b, c;
    cin >> a >> b >> c;
    int start = min(a,b);
    int end = max(a,b);
    if( start == 1 && end == 2 ){ 
      if( c > 2 ) cout << -1 << endl;
      else
        cout << (c == 1 ? 2 : 1)<< endl;
      continue;
    }
    if( end - start < 2 ) {
      cout << -1 << endl;
      continue;
    }
    --start;
    --end;
    --c;
    int max_allowed = 2 * (end - start);
    if( c > max_allowed || a > max_allowed || b > max_allowed ) {
      cout << -1 << endl;
      continue;
    }
    int opposite_to_c = (c + max_allowed/2) % max_allowed;
    cout << opposite_to_c + 1 << endl;
  }
  return 0;
}
