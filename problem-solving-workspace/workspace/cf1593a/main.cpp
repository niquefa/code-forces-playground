#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define maxel(c)         (*max_element((c).begin(),(c).end()))
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    int g = maxel(v);
    int g_count = 0;
    for( int i = 0; i < 3; ++ i ) 
      g_count += v[i] == g;

    for( int i = 0; i < 3; ++ i )
      if( g_count == 1 )
        cout << (v[i] == g ? 0 : g-v[i] + 1) << " ";
      else
        cout << (v[i] == g ? 1 : g-v[i] + 1) << " ";
    cout << endl;
  }
  return 0;
}
