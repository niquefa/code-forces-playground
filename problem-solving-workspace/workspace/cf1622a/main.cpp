#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    vector<int> sticks(3);
    for( int i = 0; i < 3; ++ i) cin >> sticks[i];
    sort(sticks.begin(), sticks.end());
    
    if( sticks[0] == sticks[1] ){
      cout << ( sticks[2] % 2 == 0 ? "YES" : "NO" ) << endl;
      continue;
    }
    if( sticks[1] == sticks[2] ){
      cout << ( sticks[0] % 2 == 0 ? "YES" : "NO" ) << endl;
      continue;
    }
    cout << ( sticks[0] + sticks[1] == sticks[2] ? "YES" : "NO" ) << endl;
  }
  return 0;
}
