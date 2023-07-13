#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    long long m;
    cin >> m;
    if( m == 1LL ) {
      cout << 0 << endl;
      continue;
    }
    if( m < 10LL ) {
      cout << m - 1 << endl;
      continue;
    }
    long long answer = -1;
    long long p10 = 1;
    while(true) {
      if( p10 > m ){ 
        answer = m - p10/10;
        break;
      }
      p10 *= 10;
    }

    cout << answer << endl;
  }
  return 0;
}
