#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");


template<class T> map<T,int> get_frequencies( const vector<T>& v ){map<T,int> ans;for( int i = 0; i < v.size(); ++ i )ans[v[i]]++;return ans;}


void solve();
int main() {
  auto start_execution_time = std::chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    //cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = std::chrono::high_resolution_clock::now();

  chrono::duration<double, std::milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];
  
  map<int,int> f = get_frequencies(a);
  //print_map(f);
  vector<int> values;
  for( auto it = f.begin(); it != f.end(); ++ it ) values.push_back(it->second);

  int ans = 0;
  //print_vector(values,"values");
  while(true) {
    int changes = 0;
    for( int i = 0; i < values.size(); ++ i) {
      if( values[i] > 0 ) {
        values[i] --;
        changes++;
      }
    }
    if( changes == 0 ) break;
    if( changes == 1 ){
      ans += 1 + *max_element(values.begin(), values.end());
      break;  
    }
    ans ++;
  }
  cout << ans << endl;
}
