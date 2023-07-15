#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

const int drd[] = {-1,-1,1,1};
const int dcd[] = {-1,1,-1,1};
#define ok(f,c,F,C)      (f>=0&&c>=0&&c<C&&f<F)
bool is_corner(const int& r, const int& c) {
  return (r == 0 && c == 0) || (r == 0 && c == 7) || (r == 7 && c == 0) || (r == 7 && c == 7);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int current_test = 0; current_test < test_cases; ++ current_test ) {
    vector<string> m(8);
    for( int i = 0; i < 8; ++ i ) cin >> m[i];

    int row = -1;
    int col = -1;

    for( int i = 0; i < 8 && row == -1 ; ++ i ) {
      for( int j = 0; j < 8 && row == -1 ; ++ j ) {
        if( m[i][j] != '#' ) continue;
        if( is_corner(i,j) ) continue;
        bool all_sharps = true;
        for( int k = 0; k < 4; ++ k ) {
          int ii = i + drd[k];
          int jj = j + dcd[k];
          if( !ok(ii,jj,8,8) ) continue;
          if( m[ii][jj] != '#' ) {
            all_sharps = false;
            break;
          }
        }
        if( all_sharps ) {
          row = i+1;
          col = j+1;
        }
      }
    }
    cout << row << " " << col << endl;
  }
  return 0;
}
