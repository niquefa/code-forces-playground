#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n, a, b;
    cin >> n >> a >> b;
    char letter = 'a';
    string ans = "";
    string ss = "";
    for( int i = 0;i < b; ++ i ) {
        ss += letter;
        letter ++;
    }
    
    while(ans.size() < n) 
      ans += ss;
    
    cout << ans.substr(0,n) << endl;
  }
  return 0;
}
