#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");
#define vap(c)           cerr <<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr <<(JJ==0?"[":"")<<c[JJ].first<<","<<c[JJ].second<<(JJ==(c).size()-1?"]\n":" | ");


void solve();
int main() {
  auto start_execution_time = chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    //cerr << "\nTest case " << current_test << endl;
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
  if( is_sorted(a.begin(),a.end()) ) {
    cout << 0 << endl;
    return;
  }

  //va(a);
  vector<pair<int,int> > v;
  for( int i = 0; i < n; ++ i) v.push_back({a[i],i+1});
  sort(v.begin(),v.end());
  //vap(v);
  int ans = 0;
  for( int i = 1; i < n; ++ i ) {
    if( v[i].second > v[i-1].second ) {
      continue;
    }
    ++ans;
  }


  cout << ans << endl;
}
