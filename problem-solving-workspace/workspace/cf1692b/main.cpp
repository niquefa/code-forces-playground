#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test__cases;
  cin >> test__cases;
  for( int current__test = 0; current__test < test__cases; ++ current__test ) {
    int n;
    cin >> n;
    vector<int> a(n);
    for( int i = 0; i < n; ++ i) cin >> a[i];
    set<int> s(a.begin(),a.end());
    int to_remove = a.size() - s.size();
    int answer = s.size();
    if( to_remove % 2 == 1 ) answer --;
    cout << answer << endl;
  }
  return 0;
}
