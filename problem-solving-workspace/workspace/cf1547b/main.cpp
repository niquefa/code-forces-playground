#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

map<char,int> get_char_frequencies( const string& v ){map<char,int> ans;for( int i = 0; i < v.size(); ++ i )ans[v[i]]++;return ans;}

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
const string ABCm = "abcdefghijklmnopqrstuvwxyz0123456789";
int find_first_char(const string& str, char c) {
    auto it = find(str.begin(), str.end(), c);
    return it == str.end() ? - 1 : distance(str.begin(), it);
}
void solve() {
  string s;
  cin >> s;
  map<char,int> f = get_char_frequencies(s);
  if( f.size() != s.size() ) {
    cout << "NO" << endl;
    return;
  }
  int index_a = find_first_char(s, 'a');
  if( index_a == -1 ) {
    cout << "NO" << endl;
    return;
  }
  string first_n = ABCm.substr(0, s.size());
  string s_sorted = s;
  sort(s_sorted.begin(), s_sorted.end());
  debug(s, s_sorted, first_n);

  if( s_sorted != first_n ) {
    cout << "NO" << endl;
    return;
  }
  bool is_valid = true;
  for( int i = index_a + 1; i < s.size(); ++ i ) {
    if( s[i-1] > s[i] ) {
      is_valid = false;
      break;
    }
  }
  for( int i = index_a - 1; i >= 0; -- i ) {
    if( s[i] < s[i+1] ) {
      is_valid = false;
      break;
    }
  }

  cout << (is_valid ? "YES" : "NO") << endl;
}
