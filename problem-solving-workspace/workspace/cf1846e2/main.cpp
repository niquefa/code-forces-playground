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
  long long n;
  cin >> n;
  if (n < 3) {
    cout << "NO" << endl;
    return;
  }
  long long d = 4*n - 3;
  long long sq = sqrt(d);
  long long sqd = -1;
  for (long long i = max(0ll, sq - 5); i <= sq + 5; ++i) {
    if (i*i == d) {
      sqd = i;
      break;
    }
  }
  if (sqd != -1 && (sqd - 1) % 2 == 0 && (sqd - 1) / 2 > 1) {
    cout << "YES" << endl;
    return;
  }

  if (solutions.count(n)) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;

  for( long long base = 2; base <= 1000000; ++base ) {
    long long current_solution = 1 + base + base * base;
    solutions.insert(current_solution);
    //debug(base, current_solution);
    long long power = base * base;
    for( int e = 3; e <= 62 ; ++ e ) {
      if( current_solution > 1e18 ) break;
      if( power > ((long long)1e18)/base ) break;

      power *= base;
      current_solution += power;
      solutions.insert(current_solution);

      //debug(base, e, power, current_solution);
    }
  }
  //print_set(solutions);
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  return 0;
}
