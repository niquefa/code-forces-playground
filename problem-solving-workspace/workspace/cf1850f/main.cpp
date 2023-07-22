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
    int n, tmp;
    cin >> n;
    vector<int> a;
    for( int i = 0; i < n; ++ i) {
      cin >> tmp;
      if(tmp > n) continue;
      a.push_back(tmp);
    };
    if( a.size() == 0 ) {
      cout << 0 << endl;
      continue;
    }
    vector<int> frequencies(n+1, 0); 
    for( int i = 0; i < a.size(); ++ i) 
      frequencies[a[i]] ++;
    
    vector<int> hit(n+1, 0);
    for( int pos = 1; pos <= n; ++ pos) 
      for( int pos_multiple = pos; pos_multiple <= n; pos_multiple += pos) 
        hit[pos_multiple] += frequencies[pos];
    cout << *max_element(hit.begin(), hit.end()) << endl;
  }
  return 0;
}
