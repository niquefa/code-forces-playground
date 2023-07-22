#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cout<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cout<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"]\n":"|");

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
    vector<int> b(n);
    for( int i = 0; i < n; ++ i) cin >> a[i] >> b[i];

    int winner = -1;
    int max_b = -1;
    for( int i = 0; i < n; ++ i ) { 
      if( a[i] <= 10 && max_b == -1 ) {
        max_b = b[i];
        winner = i;
        continue;
      }
      if( a[i] <= 10 && b[i] > max_b ) {
        max_b = b[i];
        winner = i;
      }
    }
    cout << (winner+1) << endl;
  }
  return 0;
}
