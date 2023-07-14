#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n;
    cin >> n;
    if( n < 6 ) {
      switch (n)
      {
        case 2:
        case 3:
          cout << 1 << endl;
          break;
        case 4:
        case 5:
        case 1:
          cout << 2 << endl;
          break;
      }
      continue;
    }
    cout << (n % 3 == 0 ? n/3 : n/3 + 1) << endl;
  }
  return 0;
}
