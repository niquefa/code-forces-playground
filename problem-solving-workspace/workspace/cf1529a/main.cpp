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
    for( int i = 0; i < n; ++ i) cin >> a[i];
    set<int> s(a.begin(), a.end());
    if( s.size() == 1 ) {
      cout << 0 << endl;
      continue;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int index_last = a.size() - 1;
    int index_first = 0;
    while(index_first < index_last) { 
      int first = a[index_first];
      int last = a[index_last];
      double average = (first + last) / 2.0;
      if( last > average ) {
        index_last --;
        ans ++;
      } else {
        break;
      }
    }

    cout << ans << endl;
  }
  return 0;
}
