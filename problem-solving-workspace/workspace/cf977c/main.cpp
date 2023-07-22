#include <bits/stdc++.h>
using namespace std;

template<class T> map<T,int> get_frecuencies( const vector<T>& v ){map<T,int> ans;for( int i = 0; i < v.size(); ++ i )ans[v[i]]++;return ans;}

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];
  sort(a.begin(), a.end());
  if( k == 0 ) {
    if( a[0] == 1 ) cout << -1 << endl;
    else cout << 1 << endl;
    return;
  }
  int target = a[k-1];
  if( k <= n-1 && a[k] == target ) {
    cout << -1 << endl;
    return;
  }

  if( target == 1e9 ) {
    if( a[k-1] == 1e9 ) cout << 1000000000 << endl;
    else cout << -1 << endl;
    return;
  }
  cout << target << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
    for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  return 0;
}
