#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

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
#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> v = {a, b, c};
  set<int> s(v.begin(), v.end());
  if( s.size() == 1 ) {
    cout << "YES" << endl;
    return;
  }
  for( int op = 0; op < 3; ++ op ) {
    //debug(op);
    //va(v);
    sort(v.begin(), v.end());
    s = set<int>(v.begin(), v.end());
    if( s.size() == 1 ) {
      cout << "YES" << endl;
      return;
    }
    vector<int> nv;
    for( int i = 0;i < v.size()-1; ++ i ) 
      nv.push_back(v[i]);
    int biggest_part_one = v[v.size()-1]-v[0];
    int biggest_part_two = v[v.size()-1] - biggest_part_one;
    //debug(op, biggest_part_one, biggest_part_two);
    nv.push_back(biggest_part_one);
    nv.push_back(biggest_part_two);
    sort(nv.begin(), nv.end());
    v = nv;
    //va(v);
    s = set<int>(v.begin(), v.end());
    if( s.size() == 1 ) {
      cout << "YES" << endl;
      return;
    }
  }
  
  
  cout << "NO" << endl;
}
