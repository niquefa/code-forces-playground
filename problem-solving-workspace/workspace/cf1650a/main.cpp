#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    string s, str_c;
    cin >> s >> str_c;
    char c = str_c[0];
    if( c == s[0] || c == s[s.size()-1]){
      cout << "YES" << endl;
      continue;
    }
    bool found_solution = false;
    for( int i = 0; i < s.size(); ++ i ) {
      if( i%2 == 0 && s[i] == c ) {
        cout << "YES" << endl;
        found_solution = true;
        break;
      }
    }
    if( !found_solution )
      cout << "NO" << endl;
  }
  return 0;
}
