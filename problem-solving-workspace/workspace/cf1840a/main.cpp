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
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string answer = "";
    for( int i = 0; i < n;) {
      char current_char = s[i];
      answer += current_char;
      int j = i + 1;
      while( j < n && s[j] != current_char ) ++ j;
      if( j == n ) break;
      i = j + 1;
    }

    cout << answer << endl; 
  }
  return 0;
}
