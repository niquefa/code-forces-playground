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
#define va(c)            cout<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cout<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"]\n":"|");

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n, m, h;
    cin >> n >> m >> h;
    vector<pair<pair<long long,long long>, int > > p;
    
    for( int i = 0; i < n; ++i ) {
      vector<long long> minutes(m);
      for( int j = 0; j < m; ++ j)
        cin >> minutes[j];
      sort(minutes.begin(), minutes.end());
      // va(minutes)
      vector<long long> solved_times;
      long long minutes_so_far = 0;
      for( int j = 0; j < m; ++ j) {
        minutes_so_far += minutes[j];
        solved_times.push_back(minutes_so_far);
      }
      //va(solved_times)
      long long penalty = 0;
      long long solved = 0;
      for( int j = 0; j < m; ++ j ) {
        if( solved_times[j] <= h ) {
          penalty += solved_times[j];
          solved ++;
        }
      }
      p.push_back(make_pair(make_pair(-solved, penalty), i));
    }
    sort(p.begin(), p.end());
    // for( int i = 0; i < p.size(); ++ i ) 
    //   cout << p[i].first.first << " " << p[i].first.second << " " << p[i].second << endl;

    int position = -1;
    for( int i = 0; i < p.size(); ++ i ) {
      if(p[i].second == 0) {
        position = i+1;
        break;
      }
    }
    cout << position << endl;
  }
  return 0;
}