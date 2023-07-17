#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define vaa(c)           cout<<#c << " :  "<<endl;for(int II=0;II<(c).size();++II)for(int JJ=0;JJ<(c[II]).size();++JJ)cout<<(JJ==0?"\t[":"")<<c[II][JJ]<<(JJ==(c[II]).size()-1?"]\n":"|");

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    long long n;
    cin >> n;
    if( n == 1 ) {
      cout << 1 << endl;
      continue;
    }
    if( n == 2 ) {
      cout << -1 << endl;
      continue;
    }
    vector< vector<int> > m(n, vector<int>(n, 0));
    m[0][0] = n*n;
    m[n-1][n-1] = 1;
    long long current_number = 1;
    for( int iter = 1; iter < n; ++iter ) {
      int current_row = iter;
      int current_col = 0;
      for( int cell = 0; cell <= iter; ++ cell ) {
        m[current_row][current_col] = ++current_number;
        ++current_col;
        --current_row;
      }
    }
    //vaa(m)
    for( int iter = n-1, starting_col = 1; iter >= 2; --iter, ++starting_col ) {
      int current_row = n-1;
      int current_col = starting_col;
      for( int cell = 0; cell < iter; ++ cell ) {
        m[current_row][current_col] = ++current_number;
        ++current_col;
        --current_row;
      }
    }
    //vaa(m)

    for( int i = 0; i < n; ++ i ) {
      for( int j = 0; j < n; ++ j )
        cout << m[i][j] << " ";
      cout << endl;
    }
  }
  return 0;
}
