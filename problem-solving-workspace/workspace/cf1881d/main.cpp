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
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
vector<int> find_divisors(int n) {
  vector<int> divisors;
  int limit = sqrt(n);

  for (int i = 2; i <= limit; ++i) {
    if (n % i == 0) {
      divisors.push_back(i);
      if (i != n / i) {  // Avoid adding duplicates for perfect squares
        divisors.push_back(n / i);
      }
    }
  }
  divisors.push_back(1);
  divisors.push_back(n);
  sort(divisors.begin(), divisors.end());  // To ensure the divisors are sorted

  return divisors;
}


int gcd(int a, int b) {
  while (b != 0) {
    int temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

bool can_transform_to_target(vector<int>& nums, int idx, int target) {
  if (idx == nums.size()) return true;

  if (nums[idx] == target) return can_transform_to_target(nums, idx + 1, target);

  for (int i = 0; i < nums.size(); ++i) {
    if (i != idx && nums[i] > 0) {
      int original = nums[i];
      int transformed = nums[idx] * nums[i];
      nums[i] = nums[idx] / gcd(nums[idx], nums[i]);
      nums[idx] = transformed / nums[i];
      if (can_transform_to_target(nums, idx + 1, target)) return true;
      nums[i] = original;
      nums[idx] = transformed / original;
    }
  }

  return false;
}

bool can_do_it(vector<int>& nums) {
  int target = *max_element(nums.begin(), nums.end());

  return can_transform_to_target(nums, 0, target);
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
  // for( auto x : a ) {
  //   cerr << x << " => ";
  //   vector<int> divisors = find_divisors(x);
  //   va(divisors);
  // }
  cout << (can_do_it(a) ? "YES" : "NO") << endl;
}
