#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


template<class T> void print_set(const set<T>& c, const string& set_name = "") {
  cerr << (!set_name.empty() ? set_name : "   Set : ") << "{ ";
  for(auto it = c.begin(); it != c.end(); ++it) {
    if (it != c.begin())
      cerr << " , ";
    cerr << *it;
  }
  cerr << " } " << c.size() << " Elements." << endl;
}

set<long long> solutions;

void solve() {
  int n;
  cin >> n;
  cout << (solutions.count(n) ? "YES" : "NO") << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;

  for( long long base = 2; base <= 1000; ++base ) {
    long long current_solution = 1 + base + base * base;
    solutions.insert(current_solution);
    debug(base, current_solution);
    for( int e = 3; ; ++ e ) {
      long long power = pow(base,e);
      current_solution += power;
      debug(base, e, power, current_solution);
      solutions.insert(current_solution);

      if( current_solution > 1e6 ) break;
    }
  }
  print_set(solutions);
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  return 0;
}
