#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define maxel(c)         (*max_element((c).begin(),(c).end()))

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int current_test = 0; current_test < test_cases; ++ current_test ) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for( int i = 0; i < n; ++ i) cin >> a[i];
    for( int i = 0; i < n; ++ i) cin >> b[i];
    int max_e = max(maxel(a), maxel(b));
    vector<int> minimals(n);
    for( int i = 0; i < n; ++ i) minimals[i] = min(a[i], b[i]);
    int min_product_of_max = maxel(minimals) * max_e;

    cout << min_product_of_max << '\n';
  }
  return 0;
}
