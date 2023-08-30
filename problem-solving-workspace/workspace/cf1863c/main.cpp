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
    //cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
const int MAXN = 1e5 + 1;
bool present[MAXN];
int mex(const vector<int>& a) {
  memset(present, false, sizeof(present));
  for(int val : a) {
    if (val < a.size()) 
      present[val] = true;
  }
  for(int i = 0; i <= a.size(); ++i) {
    if(!present[i]) 
      return i;
  }
  return a.size();
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];
  
  vector<int> fa(a.begin(),a.end());
  fa.push_back(mex(a));
  //va(a);
  //va(fa);

  int effShift = k % (n + 1);
  int startIndex = (n + 1) - effShift;

  for (int i = 0; i < n; ++i) {
    cout << fa[(startIndex + i) % (n + 1)] << " ";
  }
  cout << endl;
  // va(fa);
  // va(a);  
  
  // for( int op = 0; op < k; ++ op ) {
  //   vector<int> new_a(a.begin(), a.end());
  //   for( int i = 0; i < n; ++ i ) 
  //     new_a[i] = mex(new_a);
  //   a = new_a;

  //   //debug(op);
  //   va(a);
  // }
  // print_solution(a);
}
