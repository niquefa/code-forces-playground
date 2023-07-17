#include <bits/stdc++.h>
using namespace std;

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
    for( int i = 0; i < n; ++ i) cin >> a[i];
    int odd_count = 0;
    int even_count = 0;
    for( int i = 0; i < n; ++ i ) {
      if( a[i] % 2 == 0 ) {
        even_count ++;
      } else {
        odd_count ++;
      }
    }
    if( odd_count == 0 || even_count == 0 ) {
      cout << 0 << endl;
      continue;
    }
    cout << min(odd_count, even_count) << endl;
  }
  return 0;
}
