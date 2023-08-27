#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");

void print_solution( const vector<int>& solution_vector ) {
  for( int i = 0; i < solution_vector.size(); ++ i) 
    cout << (i > 0 ? " " : "") << solution_vector[i];
  cout << endl;
}

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
  int n, x, y;
  cin >> x >> y >> n;
  vector<int> a(n);
  a[0] = x;
  a[n-1] = y;
  int d = 1;
  for( int i = n-2; i > 0; --i ) {
    a[i] = a[i+1]-d;
    ++d;
  }
  
  if( a[n-1] <= a[n-2] ) {
    cout << -1 << endl;
    return;
  }
  vector<int> b;
  for( int i = 0; i < n-1; ++i ) {
    b.push_back(a[i+1]-a[i]);
  }
  //va(a)
  //va(b)
  for( int i = 1; i < b.size(); ++ i ) {
    if( b[i] >= b[i-1] ) {
      cout << -1 << endl;
      return;
    }
  }
  print_solution(a);
}
