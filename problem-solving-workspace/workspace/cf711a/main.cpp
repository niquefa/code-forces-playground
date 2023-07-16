#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int n;
  cin >> n;
  bool found_solution = false;

  vector<string> v;
  for( int i = 0; i < n; ++ i ) {
    string s;
    cin >> s;
    v.push_back(s);
    if( ( s[0] == 'O' && s[1] == 'O') || ( s[3] == 'O' && s[4] == 'O') )
      found_solution = true;
  }
  cout << (found_solution ? "YES" : "NO") << endl;
  if( !found_solution ) return 0;
  bool done = false;
  for( int i = 0; i < n; ++ i ) {
    string s = v[i];
    if( !done && s[0] == 'O' && s[1] == 'O') {
      done = true;
      cout << "++" << s[2] << s[3] << s[4] << endl;
    } else if( !done && s[3] == 'O' && s[4] == 'O') {
      done = true;
      cout << s[0] << s[1] << s[2] << "++" << endl;
    } else {
      cout << s << endl;
    }
  }
  return 0;
}
