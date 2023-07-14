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
  string s, t;
  int position = 0;
  cin >> s >> t;
  for( int i = 0; i < t.size(); ++ i ) {
    char instruction = t[i];
    if( instruction == s[position] ) {
      ++position;
    }    
  }
  cout << position + 1 << endl;
  return 0;
}
