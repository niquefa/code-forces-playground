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
    
  int n;
  cin >> n;
  vector<int> x(n);
  for( int i = 0; i < n; ++ i) cin >> x[i];

  for( int i = 0; i < n; ++ i ) {
    int distance_to_last = abs(x[i] - x[n-1]);
    int distance_to_first = abs(x[i] - x[0]);
    int distance_to_the_right = i < n - 1 ? abs(x[i] - x[i+1]) : 0;
    int distance_to_the_left = i > 0 ? abs(x[i] - x[i-1]) : 0;
    if( i == 0 ) {
      cout << distance_to_the_right << " " << distance_to_last << endl;
      continue;
    }
    if( i == n - 1 ) {
      cout << distance_to_the_left << " " << distance_to_first << endl;
      continue;
    }
    int shortest_distance = min(distance_to_the_right, distance_to_the_left);
    int longest_distance = max(distance_to_last, distance_to_first);
    cout << shortest_distance << " " << longest_distance << endl;
  }
  return 0;
}
