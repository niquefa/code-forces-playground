#include <bits/stdc++.h>
using namespace std;

const string PI = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    string s;
    cin >> s;
    int ans = 0;
    for( int i = 0; i < s.size(); ++ i) {
      if( s[i] == PI[i] ) {
        ++ ans;
      } else { 
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
