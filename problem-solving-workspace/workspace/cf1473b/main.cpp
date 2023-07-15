#include <bits/stdc++.h>
using namespace std;

bool starts_with(const std::string& str, const std::string& prefix) {
    if (prefix.length() > str.length()) 
        return false;
    
    return (str.substr(0, prefix.length()) == prefix);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int current_test = 0; current_test < test_cases; ++ current_test ) {
    string s, t;
    cin >> s >> t; 
    if( s == t ) {
      cout << s << endl;
      continue;
    }

    string long_str = s;
    string short_str = t;
    if( s.size() < t.size() ) {
      long_str = t;
      short_str = s;
    }
    if( !starts_with(long_str, short_str) ) {
      cout << -1 << endl;
      continue;
    }
    string new_str = "";
    while(true) {
      new_str += short_str;
      if( new_str.size() % long_str.size() == 0 ) 
        break;
      
    }
    string new_str_from_long_str = "";
    while(true) {
      new_str_from_long_str += long_str;
      if( new_str_from_long_str.size() == new_str.size() ) 
        break;
      
    }
    if( new_str_from_long_str != new_str ) {
      cout << -1 << endl;
      continue;
    }
    cout << new_str << endl;
  }
  return 0;
}
