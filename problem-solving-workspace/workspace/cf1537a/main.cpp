#include <bits/stdc++.h>

using namespace std;

#define accum(c)         accumulate((c).begin(),(c).end(),0)

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
    int sum = accum(a);
    if( sum == n ) {
      cout << "0\n";
      continue;
    }
    if( sum < n ) {
      cout << "1\n";
      continue;
    }
    cout << sum - n << "\n";
  }
  return 0;
}
