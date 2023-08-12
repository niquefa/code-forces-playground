#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

template<class T> map<T,int> get_frequencies( const vector<T>& v ){map<T,int> ans;for( int i = 0; i < v.size(); ++ i )ans[v[i]]++;return ans;}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    string s;
    cin >> s;
    vector<char> vs(s.begin(), s.end());
    map<char, int> frequencies = get_frequencies(vs);

    int answer = 0;
    int singles = 0;
    for( auto it = frequencies.begin(); it != frequencies.end(); ++ it )
      if( it->second > 1 ) 
        ++ answer;
      else if( it->second == 1)
        singles ++;

    cout << answer + singles / 2 << endl;

  }
  return 0;
}
