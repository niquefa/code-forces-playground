#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int current_test = 0; current_test < test_cases; ++ current_test ) {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> even_parity;
    set<int> odd_parity;
    for( int i = 0, tmp, r_to_insert; i < n; ++ i) {
      cin >> tmp;
      r_to_insert = tmp%2;
      if( i%2 == 0 )
        even_parity.insert(r_to_insert);
      else
        odd_parity.insert(r_to_insert);
    }

    cout << ( even_parity.size() <= 1 && odd_parity.size() <= 1 ? "YES" : "NO") << endl;
  }
  return 0;
}
