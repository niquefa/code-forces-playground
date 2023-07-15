#include <bits/stdc++.h>
using namespace std;

int find_longest_consecutive_0_sub_array_length( const vector<int>& a ){
  int ans = 0;
  int current = 0;
  for( int i = 0; i < a.size(); ++ i ){
    if( a[i] == 0 ){
      current ++;
      ans = max(ans,current);
    }else{
      current = 0;
    }
  }
  return ans;
}


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
    cout << find_longest_consecutive_0_sub_array_length(a) << endl;
  }
  return 0;
}
