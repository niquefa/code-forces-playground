#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

vector<long long> get_all_divisors(long long n) {
  vector<long long> divisors;
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
  debug(n);
  for( int i = 0; i < divisors.size(); ++ i ) {
    debug(divisors[i]);
  }
  return divisors;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int current_test = 0; current_test < test_cases; ++ current_test ) {
    long long n;
    cin >> n;
    vector<long long> divisors = get_all_divisors(n);
    if (divisors.size() == 0) {
      cout << "NO" << endl;
      continue;
    }
    long long a = divisors[0];
    vector<long long> divisors_of_n_by_a = get_all_divisors(n / a);
    if (divisors_of_n_by_a.size() == 0) {
      cout << "NO" << endl;
      continue;
    }
    long long b = -1;
    for( auto d : divisors_of_n_by_a ) {
      if (d != a) {
        b = d;
        break;
      }
    }
    if (b == -1) {
      cout << "NO" << endl;
      continue;
    }
    long long c = n / (a * b);
    if (c == 1 || c == a || c == b) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    cout << a << ' ' << b << ' ' << c << endl;
  }
  return 0;
}
