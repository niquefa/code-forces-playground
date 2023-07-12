#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  string answer = s.substr(0,2);
  int answer_score = 0;
  for( int i = 0; i < s.size() - 1 ; ++ i ) {
    string candidate = s.substr(i,2);
    int candidate_score = 0;
    for( int j = 0; j < s.size() - 1 ; ++ j ) { 
      if( s[j] == candidate[0] && s[j+1] == candidate[1] ) {
        candidate_score ++;
      }
    }
    if( candidate_score >= answer_score ) {
      answer = candidate;
      answer_score = candidate_score;
    }
  }
  cout << answer << endl;
  return 0;
}
