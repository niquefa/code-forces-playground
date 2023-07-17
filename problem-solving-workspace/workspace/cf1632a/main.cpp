#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    int n;
    string s;
    cin >> n >> s;
    if( n == 1 ) {
      cout << "YES" << endl;
      continue;
    }
    if( n == 2 ) {
      cout << (s[0] != s[1] ? "YES" : "NO") << endl;
      continue;
    }

    cout << "NO" << endl;
  }
  return 0;
}
