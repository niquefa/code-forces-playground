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
    debug(current_test);
    int n;
    cin >> n;
    vector<int> a;
    long long sum = 0;
    for( int i = 0, tmp; i < n; ++ i) { 
      cin >> tmp;
      if( tmp != 0 ) {
        a.push_back(tmp);
        sum += abs(tmp);
      }
        
    }
    int total_all_negatives_disjunct_sub_arrays = 0;
    //va(a);
    for( int i = 0; i < a.size(); ++ i ) {
      if( a[i] <= 0 ) {
        ++ total_all_negatives_disjunct_sub_arrays;
        debug(i);
        int j = i + 1;
        while( j < n && a[j] <= 0 ) ++ j;
        i = j - 1;
      }
    }
    cout << sum << " " << total_all_negatives_disjunct_sub_arrays << endl;
  }
  return 0;
}
