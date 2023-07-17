#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
// dp dynamic programming memoization
const int MAXN = 200002;
int n;
int a[MAXN];
long long max_from_index[MAXN];
long long max_from( const int& index ) {
  if( index >= n ) return 0;
  if( max_from_index[index] != -1 ) return max_from_index[index];
  long long ans = a[index] + max_from( index + a[index] );
  max_from_index[index] = ans;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cin >> n;
    for( int i = 0; i < n; ++ i) cin >> a[i];
    memset( max_from_index, -1, sizeof(max_from_index) );
  
    long long max_score = 0;
    for( int i = 0; i < n; ++ i)
      max_score = max( max_score, max_from(i) );
    
    cout << max_score << endl;
  }
  return 0;
}
