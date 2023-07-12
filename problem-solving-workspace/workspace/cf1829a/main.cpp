#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int differences = 0;
    string codeforces = "codeforces";
    string s;
    cin >> s;
    for( int i = 0; i < s.size() ; ++ i )
      if( s[i] != codeforces[i] )
        ++ differences;
    cout << differences << endl;
  }
  return 0;
}
