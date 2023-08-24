#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");

#define vap(c)           cerr <<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr <<(JJ==0?"[":"")<<c[JJ].first<<","<<c[JJ].second<<(JJ==(c).size()-1?"]\n":" | ");
#define vat(a,t)         cerr <<#a << " :  ";for(int JJ=0;JJ<t;++JJ)cerr <<(JJ==0?"[":"")<<a[JJ]<<(JJ==t-1?"]\n":",");
#define vaa(c)           cerr <<#c << " :  "<<endl;for(int II=0;II<(c).size();++II)for(int JJ=0;JJ<(c[II]).size();++JJ)cerr <<(JJ==0?"\t[":"")<<c[II][JJ]<<(JJ==(c[II]).size()-1?"]\n":"|");
#define vaat(c,F,C)      cerr <<#c << " :  "<<endl;for(int II=0;II<F;++II)for(int JJ=0;JJ<C;++JJ)cerr <<(JJ==0?"\t[":"")<<c[II][JJ]<<(JJ==C-1?"]\n":"|");




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
  int n;
  cin >> n;
  vector<int> a(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];

  vector<int> b(1,a[0]);
  for( int i = 1; i < n; ++ i) {
    if(a[i]>=a[i-1]) {
      b.push_back(a[i]);
    } else {
      b.push_back(a[i]);
      b.push_back(a[i]);
    }
  }

  cout << b.size() << endl;
  print_solution(b);
}
