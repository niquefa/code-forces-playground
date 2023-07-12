#include <bits/stdc++.h>
using namespace std;

long long friendships_with_n( long long n ) {
  return n * (n - 1) / 2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  if( n == m ) {
    cout << 0 << " " << 0 << endl;
    return 0;
  }
  if( m == 1 ) {
    cout << friendships_with_n(n) << " " << friendships_with_n(n) << endl;
    return 0;
  }
  long long all_in_one = n - (m - 1);
  vector<long long> ans;
  ans.push_back(friendships_with_n(all_in_one));

  long long quotient = n / m;
  long long remainder = n % m;
  long long smaller_groups_count = m - remainder;
  long long bigger_groups_count = remainder;
  long long smaller_groups_size = quotient;
  long long bigger_groups_size = quotient + 1;

  long long total_friendships_in_smaller_groups = smaller_groups_count * friendships_with_n(smaller_groups_size);

  long long total_friendships_in_bigger_groups = bigger_groups_count * friendships_with_n(bigger_groups_size);
  
  ans.push_back(total_friendships_in_smaller_groups + total_friendships_in_bigger_groups);

  sort(ans.begin(), ans.end());

  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}
