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
  auto start_execution_time = std::chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = std::chrono::high_resolution_clock::now();

  chrono::duration<double, std::milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
long long f( const long long a, const long long x ) {
  return x / a + x % a;
}
void solve() {
  long long l, r, a;
  cin >> l >> r >> a;
  long long answer = 0 ;
  if( r - l <= 600 ) {
    for( long long x = l; x <= r; ++ x ) 
      answer = max( answer, f( a, x ) );
    
  } else { 
    vector<long long> x;
    long long mid = ( l + r ) / 2;
    for( long long c = 0; c < 100; ++ c) { 
      x.push_back( l + c );
      x.push_back( r - c );
      x.push_back( mid + c );
      x.push_back( mid - c );
    }
    x.push_back(r - r%a - 1);
    for( auto& e : x ) 
      if( l <= e && e <= r)
        answer = max( answer, f( a, e ) );
  }
  
  cout << answer << endl;
}
