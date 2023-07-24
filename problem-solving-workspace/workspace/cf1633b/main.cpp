#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");
map<char,int> get_char_frequencies( const string& v ){map<char,int> ans;for( int i = 0; i < v.size(); ++ i )ans[v[i]]++;return ans;}

template<class T> void print_vector(const vector<T>& c, const string& vector_name = "") {
  cerr << (!vector_name.empty() ? vector_name : "Vector : ") << "[ ";
  for(auto it = c.begin(); it != c.end(); ++it) {
    if (it != c.begin())
      cerr << " , ";
    cerr << *it;
  }
  cerr << " ] " << c.size() << " Elements." << endl;
}

void solve() {
  string s;
  cin >> s; 
  vector<int> s0( s.size(), 0 );
  vector<int> s1( s.size(), 0 );
  if( s[0] == '0' ) s0[0] = 1;
  else s1[0] = 1;

  for( int i = 0; i < s.size(); ++ i ) {
    if( i == 0 ) continue;
    s0[i] = s0[i-1];
    s1[i] = s1[i-1];
    if( s[i] == '0' ) s0[i] ++;
    else s1[i] ++;
  }
  //print_vector(s0);
  //print_vector(s1);
  int ans = 0;
  for( int i = 0; i < s.size(); ++ i ) {
    if( s0[i] != s1[i] ) ans = max( ans, min( s0[i], s1[i] ));
  }
  cout << ans << endl;
}

int main() {
  auto start_execution_time = std::chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = std::chrono::high_resolution_clock::now();

  chrono::duration<double, std::milli> elapsed = start_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
