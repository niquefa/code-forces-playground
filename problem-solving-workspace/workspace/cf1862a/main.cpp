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
#define vaat(c,F,C)      cerr <<#c << " :  "<<endl;for(int II=0;II<F;++II)for(int JJ=0;JJ<C;++JJ)cerr <<(JJ==0?"\t[":"")<<c[II][JJ]<<(JJ==C-1?"]\n":"|");


void solve();
int main() {
  auto start_execution_time = chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
bool in_col( const vector<string>& a, const int n, const int m , const int col, const char c) {
  for( int i = 0; i < n; ++ i ) {
    if( a[i][col] == c ) return true;
  }
  return false;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  const string v = "vika";
  for( int i = 0; i < n; ++ i) cin >> a[i];
  for( int mask = 0; mask < 1<<m; ++ mask) {
    if( __builtin_popcount(mask) != 4 ) continue;
    vector<int> cols;
    for( int i = 0; i < m; ++ i ) {
      if( mask & (1<<i) ) cols.push_back(i);
    }
    bool sol = true;
    for( int i = 0; i < 4; ++ i ) {
      if( !in_col(a, n, m, cols[i], v[i]) ){
        sol = false;
        break;
      }
    }
    if( sol ) {
      cout << "YES" << endl;
      return;
    }
  }
  
  cout << "NO" << endl;
}
