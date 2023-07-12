#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = s.size();
    for( int i = 0, j = s.size() -1; i < s.size()/2; ++ i, --j)
      if( s[i] != s[j] )
        ans -= 2;
      else
        break;
    cout << ans << endl;
  }
  return 0;
}
