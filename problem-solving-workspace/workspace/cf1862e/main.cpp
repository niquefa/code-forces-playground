#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");

template<class T> void print_vector(const vector<T>& c, const string& vector_name = "") {
  cerr << (!vector_name.empty() ? vector_name : "Vector : ") << "[ ";
  for(auto it = c.begin(); it != c.end(); ++it) {
    if (it != c.begin()) cerr << " , ";
    cerr << *it;
  }
  cerr << " ] " << c.size() << " Elements." << endl;
}

template<class T> void print_multi_set(const multiset<T>& c, const string& set_name = "") {
  cerr << (!set_name.empty() ? set_name : "   MultiSet : ") << "{ ";
  for(auto it = c.begin(); it != c.end(); ++it) {
    if (it != c.begin()) cerr << " , ";
    cerr << *it;
  }
  cerr << " } " << c.size() << " Elements in multiset." << endl;
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
  int n, m;
  long long d;
  cin >> n >> m >> d;
  vector<int> a(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];

  long long ans = 0, sum = 0;
  multiset<int> st;
  debug(n,m,d);
  for (int i = 0; i < n; ++i)
  {
    if (a[i] > 0)
    {
      ans = max(ans, sum + a[i] - d * (i + 1));
      st.emplace(a[i]);
      sum += a[i];
      if ((int)st.size() == m) {
        sum -= *st.begin();
        st.erase(st.begin());
      } 
    }
    debug(i,ans,sum);
    print_multi_set(st);
  }
  debug(ans);
  cout << ans << '\n';
}
