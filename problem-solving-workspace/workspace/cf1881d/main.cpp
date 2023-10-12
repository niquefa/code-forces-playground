#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");

void solve();
int main() {
  auto start_execution_time = chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    //cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}

int gcd(int a, int b) {
  while (b != 0) {
    int temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

map<int, int> prime_factors(int n) {
  map<int, int> factors;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      factors[i]++;
      n /= i;
    }
  }
  if (n > 1) factors[n]++;
  return factors;
}

bool can_do_it(vector<int>& nums) {
  map<int, int> total_prime_counts;
  for (int num : nums) {
    map<int, int> factors = prime_factors(num);
    for (auto [prime, count] : factors) {
      total_prime_counts[prime] += count;
    }
  }

  int n = nums.size();
  for (auto [prime, count] : total_prime_counts) {
    if (count % n != 0) return false;
  }

  return true;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];
  sort(a.begin(), a.end());
  set<int> s(a.begin(), a.end());
  if( s.size() == 1 ) {
    cout << "YES" << endl;
    return;
  }
  cout << (can_do_it(a) ? "YES" : "NO") << endl;
}
