#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>
#include <sstream>
#include <utility>
#include <cctype>
#include <numeric>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <limits>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <functional>
#include <inttypes.h>
#include <fstream>
using namespace std;

const int dr8[] = {-1,-1,-1  ,  0,0  ,   1,1,1};
const int dc8[] = {-1, 0, 1  , -1,1  ,  -1,0,1};
#define ok(f,c)      (f>=0&&c>=0&&c<3&&f<3)

bool won( const vector<string> m, const char p ) {
  for(int r = 0; r < 3; ++ r ) {
    for( int c = 0; c < 3; ++c ) {
      if( m[r][c] != p ) continue;
      for( int d = 0; d < 8; ++ d ) {
        int p_matches = 1;
        int nr = r;
        int nc = c;
        for( int i = 0; i < 2; ++i ) {
          nr += dr8[d];
          nc += dc8[d];

          if(!ok(nr,nc)) break;
          if( m[nr][nc] != p ) break;
          ++ p_matches;
        }
        if( p_matches == 3 ) return true;
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    vector<string> m(3);
    for( int i = 0; i < 3; ++ i ) cin >> m[i];
    bool wonX = won(m, 'X');
    bool wonO = won(m, 'O');
    bool wonP = won(m, '+');
    if( wonX ) cout << "X" << endl;
    else if( wonO ) cout << "O" << endl;
    else if( wonP ) cout << "+" << endl;
    else cout << "DRAW" << endl;
  }
  return 0;
}