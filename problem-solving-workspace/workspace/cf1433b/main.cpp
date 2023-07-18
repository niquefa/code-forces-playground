#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cout<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cout<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"]\n":"|");
vector<string> tokenize(const string& str, const string& d = " "){vector <string> t;int up  = str.find_first_not_of(d, 0);int pos = str.find_first_of(d, up);while (string::npos != pos || string::npos != up){t.push_back(str.substr(up, pos - up));up = str.find_first_not_of(d, pos);pos = str.find_first_of(d, up);}return t;}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    int n;
    cin >> n;
    string s = "", tmp;
    for( int i = 0; i < n; ++ i) {
      cin >> tmp;
      s += tmp;
    }
    while( s.size() > 0 && s[0] == '0' )
      s.erase(0, 1);
    while( s.size() > 0 && s[s.size() - 1] == '0' )
      s.erase(s.size() - 1, 1);
    vector<string>  tokens = tokenize(s, "0");
    int ans = s.size();
    
    for( auto& token : tokens )
      ans -= token.size();

    cout << ans << '\n';
  }
  return 0;
}
