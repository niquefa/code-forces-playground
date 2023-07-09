#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int a, b, c, x, y, z; 
    cin >> x >> y >> z;
    vector<int> v(3);
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v.push_back(1);
    v.push_back(1);
    sort( v.begin(), v.end() );
    bool solution_found = false;
    do {
      a = v[0];
      b = v[1];
      c = v[2];
      if( max(a,b) == x && max(a,c) == y && max(b,c) == z ) {
        cout << "YES" << endl << a << " " << b << " " << c << endl;
        solution_found = true;
        break;
      }

    } while( next_permutation( v.begin(), v.end() ) );
    if( !solution_found)
      cout << "NO" << endl;
  }
  return 0;
}
