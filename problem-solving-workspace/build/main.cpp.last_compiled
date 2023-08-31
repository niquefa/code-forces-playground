#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
 
#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");
 
 
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
void solve() {
  string s;
  cin >> s;
  int n = (int) s.size();
  int cnt = 0;
  map<int,int> is_sorted_check;
  
  for( int i = 0; i < n; ++ i ) {
    if( s[i] == '+')
      ++cnt;
    if( s[i] == '-' )
      --cnt;
    if ( cnt < 0 ) {
      cout << "NO" << endl;
      return;
    }
    if( s[i] == '0' )
      is_sorted_check[0]++;
    if( s[i] == '1' )
      is_sorted_check[1]++;
    if( s[i] == '0') {
      if( i == 0 || cnt < 2 || s[i-1] == '1') {
        cout << "NO" << endl;
        return;
      }
    }
    if( s[i] == '1') {
      if( i > 0 && s[i-1] == '0') {
        cout << "NO" << endl;
        return;
      }
    }
  }
  if( is_sorted_check.size() <= 1 ) {
    cout << "YES" << endl;
    return;
  }
  vector<int> x;
  int current_to_add = 2;
  set<int> fixed;
  for( int i = 0; i < n; ++ i ) {
    if( s[i] == '+')
      x.push_back(current_to_add++);
    if( s[i] == '-' ){
      x.pop_back();
    }
    if( s[i] == '0' ){
      int last = x[x.size()-1];
      if( fixed.count(last) > 0  ) {
        cout << "NO" << endl;
        return;
      }
      x[x.size()-1] = 1;
      if( is_sorted(x.begin(),x.end())){
        cout << "NO" << endl;
        return;
      }
    }
      
    if( s[i] == '1' && !is_sorted(x.begin(),x.end()) ) {
      cout << "NO" << endl;
      return;
    } 
    if( s[i] == '1' ) {
      fixed.insert(current_to_add-1);
    }

  }
  cout << "YES" << endl;
}