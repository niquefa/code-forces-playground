#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int number_of_QAQ_subsequences = 0;
  string s;
  cin >> s;
  int n = s.size();
  for( int i = 0; i < n; ++i ) {
    if( s[i] != 'Q' ) continue;
    for( int j = i + 1; j < n; ++ j ) {
      if( s[j] != 'A' ) continue;
      for( int k = j + 1; k < n; ++ k ) {
        if( s[k] != 'Q' ) continue;
        ++ number_of_QAQ_subsequences;
      }
    }
  }

  cout << number_of_QAQ_subsequences << endl;
  return 0;
}
