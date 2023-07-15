#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    string s;
    cin >> s;
    int ones = count(s.begin(), s.end(), '1');
    int zeroes = count(s.begin(), s.end(), '0');
    int min_digits = min(ones, zeroes);

    cout << (min_digits % 2 == 1 ? "DA" : "NET") << endl;
  }
  return 0;
}
