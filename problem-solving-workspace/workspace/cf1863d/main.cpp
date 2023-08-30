#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");

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
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
void solve() {
  int n, m;
  cin >> n >> m ;
  vector<string> a(n);

  for( int i = 0; i < n; ++ i) cin >> a[i];
  vector<int> row_sum(n,0), col_sum(m,0);
  for( int i = 0; i < n; ++ i ) {
    for( int j = 0; j < m ; ++ j ) {
      if( a[i][j] != '.' ) {
        row_sum[i] ++;
        col_sum[j] ++;
      }
    }
  }

  for( int i = 0; i < n; ++i ) 
    if( row_sum[i]%2 == 1 ) 
    {
      cout << -1 << endl;
      return;
    }
  for( int j = 0; j < m; ++j )
    if( col_sum[j]%2 == 1 ) 
    {
      cout << -1 << endl;
      return;
    }

  for( int i = 0; i < n - 1; ++ i ) {
    vector<int> u_col;
    for( int j = 0; j < m; ++ j ) {
      if( a[i][j] == 'U' ) {
        u_col.push_back(j);
      }
    }
    if( u_col.size()%2 != 0 ){
      cout << -1 << endl;
      return;
    }
    for( int k = 0; k < (int)u_col.size(); ++k ){
      int j = u_col[k];
      if( k % 2 == 0 ){
        a[i][j] = 'W';
        a[i+1][j] = 'B';
      } else { 
        a[i][j] = 'B';
        a[i+1][j] = 'W';
      }
    }
  }
  for( int j = 0; j < m - 1; ++ j ) {
    vector<int> l_row;
    for( int i = 0; i < n; ++ i ) {
      if( a[i][j] == 'L' ) {
        l_row.push_back(i);
      }
    }
    if( l_row.size()%2 != 0 ){
      cout << -1 << endl;
      return;
    }
    for( int k = 0; k < (int)l_row.size(); ++k ){
      int i = l_row[k];
      if( k % 2 == 0 ){
        a[i][j] = 'W';
        a[i][j+1] = 'B';
      } else { 
        a[i][j] = 'B';
        a[i][j+1] = 'W';
      }
    }
  }


  for(auto &row : a) 
    cout << row << "\n";
  
}
