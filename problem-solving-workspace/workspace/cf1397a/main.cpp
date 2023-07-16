#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

template<class T> map<T,int> get_frecuencies( const vector<T>& v ){map<T,int> ans;for( int i = 0; i < v.size(); ++ i )ans[v[i]]++;return ans;}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    int n;
    cin >> n;
    string s;
    int total_characters = 0;
    map<char, int> frec;
    for( int i = 0; i < n; ++ i) {
      cin >> s;
      for( auto c : s ) 
        frec[c] ++;
      
      total_characters += s.size();
    } 
    if( total_characters % n != 0 ) {
      cout << "NO" << endl;
      continue;
    }
    bool solution = true;
    for( auto it = frec.begin(); it != frec.end(); ++ it ) {
      if( it->second % n != 0 ) {
        solution = false;
        break;
      }
    }
    cout << (solution ? "YES" : "NO") << endl;
  }
  return 0;
}
