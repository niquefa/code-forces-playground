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
    string s;
    cin >> s;
    int n = s.size();
    debug(current_test);
    string ss = s;
    while( ss.size() > 0 && ss[0] == '0' ) 
      ss.erase(0, 1);
    
    while( ss.size() > 0 && ss[ss.size() - 1 ] == '0' ) 
      ss.erase(ss.size() - 1, 1);
    
    debug(s);
    debug(ss);

    vector<string> tokens = tokenize(ss, "0");
    
    int total_ones = 0;
    for( int i = 0; i < tokens.size(); ++ i ) 
      total_ones += tokens[i].size();

    cout << ss.size() - total_ones << endl;
  }
  return 0;
}
