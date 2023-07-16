#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
#define va(c)            cout<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cout<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"]\n":"|");

int gcd(int a, int b) {
    if (a == 0) {
        return 0;
    }
    if (b == 0) {
        return 1;
    }
    if (a >= b) {
        int r = a % b;
        int k = a / b;
        if (k % 2 == 1) {
            return gcd(b, r) + k + k / 2;
        } else {
            return gcd(r, b) + k + k / 2;
        }
    }
    return 1 + gcd(b, abs(a - b));
}
vector<int> get_differences( const vector<int>& a, const vector<int>& b ){
  vector<int> ans(a.size());
  for( int i = 0; i < a.size(); ++ i ) ans[i] = abs( a[i] - b[i] );
  return ans;
}
bool vectors_are_equal( const vector<int>& a, const vector<int>& b ){
  return a.size() == b.size() && equal(a.begin(), a.end(), b.begin());
}
bool all_are_zero( const vector<int>& a ) {
  for( int i = 0; i < a.size(); ++ i )
    if( a[i] != 0 ) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    int n;
    cin >> n;
    vector<int> a(n);
    for( int i = 0; i < n; ++ i) cin >> a[i];
    vector<int> b(n);
    for( int i = 0; i < n; ++ i) cin >> b[i];

    if( all_are_zero(a) || all_are_zero(b) ){
      cout << "YES" << endl;
      continue;
    }
    vector<int> c = get_differences(a, b);
    if( all_are_zero(c) ){
      cout << "YES" << endl;
      continue;
    }
    set<int> remainders_in_3;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0 && b[i] == 0) {
            continue;
        }
        remainders_in_3.insert(gcd(a[i], b[i]) % 3);
    }
    
    cout << (remainders_in_3.size() <= 1 ? "YES" : "NO") << endl;
  }
  return 0;
}
