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

const int dx[]  = {-1,0,0,1};
const int dy[]  = {0,-1,1,0};
int main() {
  const string MOVES = "LDUR";
  map<char,int> next_x;
  map<char,int> next_y;
  for( int i = 0; i < MOVES.size(); ++ i ) {
    next_x[MOVES[i]] = dx[i];
    next_y[MOVES[i]] = dy[i];
  }
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n;
    cin >> n;
    bool got_to_1_1 = false;
    string moves;
    cin >> moves;
    int current_x = 0;
    int current_y = 0;
    for( auto move : moves ) {
      current_x = current_x + next_x[move];
      current_y = current_y + next_y[move];
      if( current_x == 1 && current_y == 1 ) {
        got_to_1_1 = true;
        break;
      }
    }
    cout << (got_to_1_1 ? "YES" : "NO") << endl;
  }
  return 0;
}
