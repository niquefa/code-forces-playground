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
    cout << (n%2 == 0 && (n/2)%2 == 0 ? "YES" : "NO") << endl;
  }
  return 0;
}
