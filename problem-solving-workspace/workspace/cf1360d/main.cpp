#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


vector<long long> get_all_divisors(long long n) {
  vector<long long> divisors;
  divisors.push_back(1); // Remove to not include 1
  for (int i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      if (n / i == i) {
        divisors.push_back(i);
      } else {
        divisors.push_back(i);
        divisors.push_back(n / i);
      }
    }
  }
  sort(divisors.begin(), divisors.end());
  divisors.push_back(n); // Remove to not include n
  return divisors;
}
long long largest_lower_or_equal(const std::vector<long long>& v, long long k) {
  auto it = std::upper_bound(v.begin(), v.end(), k);
  return it == v.begin() ? -1 : *(--it);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    long long n , k;
    cin >> n >> k;
    if( k == 1 ) {
      cout << n << endl;
      continue;
    }
    if( k >= n ) {
      cout << 1 << endl;
      continue;
    }
    vector<long long> divisors = get_all_divisors(n);
    long long ans = largest_lower_or_equal(divisors, k);
    if( ans == -1 ) {
      cout << 1 << endl;
    } else {
      cout << n / ans << endl;
    }
  }
  return 0;
}
