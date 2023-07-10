#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string c;
  cin >> c;
  vector<string> k(5);
  for( int i = 0; i < 5; ++ i ) cin >> k[i];
  for( int i = 0; i < 5; ++ i ) {
    if( c[0] == k[i][0] || c[1] == k[i][1] ) {
      cout << "YES\n";
      return 0;
    }   
  }
  cout << "NO\n";
  return 0;
}
