#include <bits/stdc++.h>
using namespace std;


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

set<char> set_intersection(const set<char>& a, const set<char>& b) {
    set<char> result;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(result, result.begin()));
    return result;
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  set<char> a;
  set<char> b;
  for( int i = 0; i < s.size(); ++ i ) {
    if( i % 2 == 0 ) a.insert(s[i]);
    else b.insert(s[i]);
  }
  
  set<char> c = set_intersection(a,b);

  cout << (c.size() == 0 ? "YES" : "NO") << endl;

}
