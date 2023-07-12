#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n;
    cin >> n;
    vector<long long> c(n);
    long long max_element = -999999999999LL;
    for( int i = 0; i < n; ++ i){
      cin >> c[i];
      max_element = max(max_element, c[i]);
    }
    if( max_element <= 0 ) {
      cout << max_element << endl;
      continue;
    }
    if( n == 1 ) {
      cout << c[0] << endl;
      continue;
    }
    long long evens = 0;
    long long odds = 0;
    for( int i = 0; i < n; ++ i){
      if( i % 2 == 0 ) evens += max(c[i],0LL);
      else odds += max(c[i],0LL);
    }
    long long answer = max(evens, odds);
    cout << answer << endl;
  }
  return 0;
}
