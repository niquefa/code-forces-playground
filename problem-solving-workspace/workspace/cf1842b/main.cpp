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
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n, x;
    cin >> n >> x;
    int knowledge = 0, book;
    vector<vector<int> > stacks(3, vector<int>(n));
    for( int stack = 0; stack < 3; ++ stack)
      for( int i = 0; i < n; ++ i)
        cin >> stacks[stack][i];
    
    for( int stack = 0; stack < 3; ++ stack)
      for( int i = 0; i < n; ++ i) {
        book = stacks[stack][i];
        if( (x|book) != x)
          break;
        knowledge |= book;
      };
    
    cout << (knowledge == x ? "Yes" : "No") << endl;
  }
  return 0;
}
