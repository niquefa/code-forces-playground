#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");



void solve();
int main() {
  auto start_execution_time = chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];
  
  if( n == 1 ) {
    cout << (a[0] == 1 ?"YES":"NO") << endl;
    return ;
  }
  if( a[0] != n ) {
    cout << "NO" << endl;
    return ;
  }
  //va(a);
  int index_first_flaw = -1;
  for( int i = 0; i < n; ++ i ) {
    if( a[i] <= i) {
      index_first_flaw = i;
      break;
    }
  }
  //debug(index_first_flaw);
  if( index_first_flaw == -1 ) {
    cout << "YES" << endl;
    return ;
  }
  auto comparator = [&](int val, int index) {
    return val >= index + 1;
  };
  for( int i = index_first_flaw; i < n; ++ i ) {
    int diff = i - a[i] + 1;
    // debug(i,diff);
    // int index_to_the_left_with_a_i_greater_or_equal_to_i = -1;
    // for( int j = i-1; j >=0 ; --j ) {
    //   if( a[j] >= i + 1 ) {
    //     index_to_the_left_with_a_i_greater_or_equal_to_i = j;
    //     break;
    //   }
    // }
    auto it = std::lower_bound(a.begin(), a.begin() + i, i, comparator);
    int index = std::distance(a.begin(), it) - 1;


    //debug(index_to_the_left_with_a_i_greater_or_equal_to_i, index);
    int diff2 = i - index;
    //debug(diff,diff2);
    if( diff != diff2 ) {
      cout << "NO" << endl;
      return ;
    }
  }
  cout << "YES" << endl;
}
