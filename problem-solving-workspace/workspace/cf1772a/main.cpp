#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    string s;
    cin >> s;
    cout << (s[0]+s[2]-'0'-'0') << endl;
  }
  return 0;
}
