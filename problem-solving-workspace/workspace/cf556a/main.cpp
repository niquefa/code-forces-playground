#include <bits/stdc++.h>

using namespace std;

#define countx(c,x)      std::count((c).begin(),(c).end(),x)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  cout << (abs(countx(s,'0') - countx(s,'1'))) << endl;
  return 0;
}
