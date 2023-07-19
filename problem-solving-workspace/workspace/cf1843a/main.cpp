#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cout<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cout<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"]\n":"|");

#define vx(x)            cout<<"{ " << #x << " = "<<x<<" }"<<endl;

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
    int ans = 0;
    sort(a.begin(), a.end());
    for( int i = 0, j = n-1; i < n/2; ++ i, --j ) 
      ans += abs(a[i] - a[j]);
    
    cout << ans << endl;
  }
  return 0;
}
