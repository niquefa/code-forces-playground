#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

const long long MAX = 1000000000LL;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  set<long long> all_squares_and_cubes;
  
  long long n = 1;
  while(n*n <= MAX) {
    all_squares_and_cubes.insert(n*n);
    n++;
  }
    
  n = 1;
  while(n*n*n <= MAX) {
    all_squares_and_cubes.insert(n*n*n);
    n++;
  }
  debug(all_squares_and_cubes.size());
  vector<long long> v(all_squares_and_cubes.begin(), all_squares_and_cubes.end());
  v.push_back(MAX + 1);
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    int x;
    cin >> x;
    int count = lower_bound(v.begin(), v.end(), x + 1) - v.begin();
    cout << count << "\n";
  }
  return 0;
}
