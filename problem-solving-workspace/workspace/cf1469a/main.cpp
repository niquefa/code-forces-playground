#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
template<class T> string grow_to_size( T element , int size_to_get , const string& str_to_append = " " ){
  string answer = to_string(element);
  while( answer.size() < size_to_get )
    answer = str_to_append + answer;
  return answer;
}
void print_char_map(const map<char, int>& m, const string& map_name = "") {
  cerr << (!map_name.empty() ? map_name : "CharMap:") << " {" << endl;
  int max_value_length = 0;
  for(auto it = m.begin(); it != m.end(); ++it)
    max_value_length = max(max_value_length, (int)to_string(it->second).size());

  for(auto it = m.begin(); it != m.end(); ++it) {
    cerr << " " << (it->first) << " -> " << grow_to_size(it->second, max_value_length + 1) << " ";
    for( int i = 0; i < it->second; ++ i ) cerr << "*";
    cerr << endl;
  }
  cerr << "} " << m.size() << " <char,int> pairs." << endl;
}

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

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  if( s[0] == ')' || s[n-1] == '(' ) {
    cout << "NO" << endl;
    return;
  }
  map<char,int> m = get_char_frequencies(s);
  print_char_map(m);
  if ( (m['('] + m[')'] + m['?'] ) % 2 != 0 ) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}