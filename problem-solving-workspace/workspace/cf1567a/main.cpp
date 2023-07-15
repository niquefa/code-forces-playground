#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  const string KEYS   = "LRDU";
  const string VALUES = "LRUD";

  map<char,char> m;

  for ( int i = 0; i < KEYS.size(); ++ i ) 
    m[KEYS[i]] = VALUES[i];

  int test_cases;
  cin >> test_cases;
  for( int current_test = 0; current_test < test_cases; ++ current_test ) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for( int i = 0; i < n; ++ i )
      cout << m[s[i]];
    cout << endl;
  }
  return 0;
}
