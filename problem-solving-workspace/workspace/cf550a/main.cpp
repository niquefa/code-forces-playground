#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int find_first_substring(const string& str, const string& substr) {
    size_t found = str.find(substr);
    return found != string::npos ? static_cast<int>(found) : -1; 
}

int find_last_substring(const string& str, const string& substr) {
    size_t found = str.rfind(substr);
    return found != string::npos ? static_cast<int>(found) : -1; 
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  while( cin >> s ) {
    int a = find_first_substring(s, "AB");
    int b = find_last_substring(s, "BA");
    int aa = find_last_substring(s, "AB");
    int bb = find_first_substring(s, "BA");
    
    debug(a);
    debug(b);
    cout << (a >= 0 && b >= 0 && (abs(a-b) > 1 || abs(aa-bb) > 1) ?  "YES" : "NO") << endl;
  }
  return 0;
}
