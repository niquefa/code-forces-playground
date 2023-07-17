#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    int n;
    cin >> n;
    set<string> s;
    string melody;
    cin >> melody;
    for( int i = 0; i < melody.size() - 1; ++ i ) {
      string tmp = "";
      tmp += melody[i];
      tmp += melody[i + 1];
      s.insert(tmp);
    }
    cout << s.size() << endl;
  }
  return 0;
}
