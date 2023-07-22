#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,long long> m[4];
    for( int i = 0; i < n; ++ i) {
      int x , y;
      cin >> x >> y;
      m[0][x]++;
      m[1][y]++;
      m[2][x+y]++;
      m[3][x-y]++;
    }
    long long answer = 0;

    for( int i = 0; i < 4; ++ i) 
      for( auto it = m[i].begin(); it != m[i].end(); ++ it) 
        answer += (long long)it->second * (it->second-1);
    cout << answer << endl;
  }
  return 0;
}
