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
    //cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = chrono::high_resolution_clock::now();
 
  chrono::duration<double, milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
long long gcd(long long a, long long b) {
  if( b == 0 ) return a;
  return gcd(b, a%b);
}
void solve() {
  long long n;
  long long x, y;
  cin >> n >> x >> y;
  
  long long diff = y - x;
  if( diff == 0 ) {
    cout << 0 << endl;
    return;
  }
  long long lcm = (long long)x * y / gcd(x, y);
  
  int only_div_by_x = (n / x) - (n / lcm);
  int only_div_by_y = (n / y) - (n / lcm);
    
  long long sx = ((long long)n*(n+1))/2 - ((long long)(n-only_div_by_x)*(n-only_div_by_x+1))/2;
  long long sy = ((long long)only_div_by_y*(only_div_by_y+1))/2;
  
  cout << sx - sy << endl;
}