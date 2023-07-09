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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n;
    cin >> n;
    vector<int> v(n);
    for( int i = 0; i < n; ++ i ) cin >> v[i];
    vector<bool> visited(n,false);
    int to_right = 0;
    int to_left = n-1;
    bool left_turn = false;
    while(true){
      int current_index;
      if(left_turn){
        current_index = to_left;
        --to_left;
      } else {
        current_index = to_right;
        ++to_right;
      }
      if(visited[current_index]) break;
      visited[current_index] = true;
      cout << v[current_index] << " ";
      left_turn = !left_turn;
    }
    cout << endl;
  }
  return 0;
}