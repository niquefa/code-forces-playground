#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

bool custom_cmp(int a, int b) {
    if (a % 2 == 0 && b % 2 == 0) {
        return a > b;
    } else if (a % 2 != 0 && b % 2 != 0) {
        return a < b;
    } else {
        return a % 2 == 0;
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n;
    cin >> n;
    vector<int> a(n);
    for( int i = 0; i < n; ++ i) cin >> a[i];
    sort(a.begin(), a.end(), custom_cmp);

    bool always_even_greater = true;
    int even_sum = 0;
    int odd_sum = 0;
    for( int i = 0; i < n; ++ i ) {
        if (a[i] % 2 == 0) {
            even_sum += a[i];
        } else {
            odd_sum += a[i];
        }
        if (even_sum <= odd_sum) {
            always_even_greater = false;
            break;
        }
    }

    cout << (always_even_greater ? "YES" : "NO") << endl;
  }
  return 0;
}
