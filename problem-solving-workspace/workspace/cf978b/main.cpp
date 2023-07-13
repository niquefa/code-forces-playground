#include <bits/stdc++.h>
using namespace std;

vector<string> tokenize(const string& str, const string& d = " "){vector <string> t;int up  = str.find_first_not_of(d, 0);int pos = str.find_first_of(d, up);while (string::npos != pos || string::npos != up){t.push_back(str.substr(up, pos - up));up = str.find_first_not_of(d, pos);pos = str.find_first_of(d, up);}return t;}
#define va(c)            cout<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cout<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"]\n":"|");

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  vector<string> tokens = tokenize(s, "abcdefghijklmnopqrstuvwyz");
  //va(tokens);
  for( auto t : tokens )
    ans += t.size() > 2 ? t.size() - 2 : 0;

  cout << ans << endl;
  return 0;
}
