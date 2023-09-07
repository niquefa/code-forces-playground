#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");
const int MAX = 10000000;
vector<bool> is_prime(MAX+1, true);
vector<int> primes;
void fill_primes() {
  is_prime[0] = is_prime[1] = false;

  for(int i = 2; i * i <= MAX; ++i) {
    if(is_prime[i]) {
      for(int j = i * i; j <= MAX; j += i) {
        is_prime[j] = false;
      }
    }
  }
  for(int i = 2; i <= MAX; ++i) {
    if(is_prime[i]) {
      primes.push_back(i);
    }
  }
}
void solve();
int main() {
  auto start_execution_time = chrono::high_resolution_clock::now();
  fill_primes();
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
int gcd(int a, int b) {
  if( b == 0 ) return a;
  return gcd(b, a%b);
}

pair<int, int> find_pair(int n) {
  for (int a = 2; a <= n / 2; ++a) {
    int b = n - a;
    if (gcd(a, b) != 1) {
      return {a, b};
    }
  }
  return {-1, -1};
}


void solve() {
  int l, r;
  cin >> l >> r;
  if( l == 1 && r <= 3 ) {
    cout << -1 << endl;
    return;
  }
  if( l == 2 && r <= 3 ) {
    cout << -1 << endl;
    return;
  }
  if( l == 3 && r <= 3 ) {
    cout << -1 << endl;
    return;
  }
  if( l >= 4 && l % 2 == 0 ) {
    cout << l/2 << " " << l/2 << endl;
    return;
  }
  if( l == 2 && l + 2 <= r ) {
    cout << (l+2)/2 << " " << (l+2)/2 << endl;
    return;
  }
  if( r%2 == 0 ) {
    cout << r/2 << " " << r/2 << endl;
    return;
  }
  if( r-1 >= l && gcd((r-1)/2, (r-1)/2) != 1) {
    cout << (r-1)/2 << " " << (r-1)/2 << endl;
    return;
  }
  if( l%2 == 1 && l+1 <= r ) {
    cout << (l+1)/2 << " " << (l+1)/2 << endl;
    return;
  }
  if( l == r && is_prime[l] ) {
    cout << -1 << endl;
    return;
  }

  for( int x = l; x <= r; ++x ) {
    pair<int,int> p = find_pair(x);
    if( p.first != -1 ) {
      cout << p.first << " " << p.second << endl;
      return;
    }
  }
  cout << -1 << endl;
}

