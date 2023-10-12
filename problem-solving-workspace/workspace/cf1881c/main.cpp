#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");

#define vap(c)           cerr <<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr <<(JJ==0?"[":"")<<c[JJ].first<<","<<c[JJ].second<<(JJ==(c).size()-1?"]\n":" | ");
#define vat(a,t)         cerr <<#a << " :  ";for(int JJ=0;JJ<t;++JJ)cerr <<(JJ==0?"[":"")<<a[JJ]<<(JJ==t-1?"]\n":",");
#define vaa(c)           cerr <<#c << " :  "<<endl;for(int II=0;II<(c).size();++II)for(int JJ=0;JJ<(c[II]).size();++JJ)cerr <<(JJ==0?"\t[":"")<<c[II][JJ]<<(JJ==(c[II]).size()-1?"]\n":"|");

void solve();
int main() {
  auto start_execution_time = chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    //cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
vector<pair<int, int>> rotate_positions(const vector<string>& a, int r, int c) {
  int n = a.size();
  int m = a[0].size();
  
  vector<pair<int, int>> positions;
  
  positions.push_back({r, c});
  positions.push_back({c, n - 1 - r});    // 90 degrees clockwise
  positions.push_back({n - 1 - r, m - 1 - c});    // 180 degrees clockwise
  positions.push_back({m - 1 - c, r});    // 270 degrees clockwise
  
  return positions;
}
int get_cost_of_equalize( vector<char>& v) {
  sort(v.begin(), v.end());
  int ans = 0;
  for( int i = 0; i < (int)v.size(); ++ i ) 
    ans += v[v.size()-1] - v[i];

  return ans;
}
void solve() {
  int n;
  cin >> n;
  vector<string> a(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];
  int ans = 0;
  //vaa(a);
  set<pair<int, int>> visited;
  for( int i = 0;i < n; ++ i ) {
    for( int j = 0; j < n; ++ j ) {
      pair<int,int> key = {i, j};
      if( visited.count(key) ) continue;
      visited.insert(key);
      vector<pair<int, int>> positions = rotate_positions(a, i, j);
      vector<char> values;
      for( int k = 0; k < (int)positions.size(); ++ k ) {
        pair<int, int> position = positions[k];
        visited.insert(position);
        values.push_back(a[position.first][position.second]);
      }
      ans += get_cost_of_equalize(values);
    }
  }

  cout << ans << endl;
}
