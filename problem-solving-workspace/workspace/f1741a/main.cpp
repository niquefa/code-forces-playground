#include <bits/stdc++.h>
using namespace std;

int score( const string& s ) {
  if( s == "M" ) return 0;
  int x_count = count(s.begin(), s.end(), 'X');
  return s[s.size()-1] == 'S' ? - x_count -1 : x_count + 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int current_test = 0; current_test < test_cases; ++ current_test ) {
    string a, b;
    cin >> a >> b;
    if( a == b ) {
      cout << "=" << endl;
      continue;
    }
    cout << ( score(a) > score(b) ? ">" : "< ") << endl;
  }
  return 0;
}
