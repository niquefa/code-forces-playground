#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void print_vector(const vector<int>& a) {
  for( int i = 0; i < a.size(); ++ i )
    cout << a[i];
  cout << endl;
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
    string s;
    cin >> s;
    vector<int> a(n, 1);
    vector<int> b(n, 1);
    bool first_zero = true;
    for( int i = 1; i < n; ++ i ) {
      switch (s[i])
      {
        case '0':
          a[i] = 0;
          b[i] = 0;
          break;
        case '1':
          if( first_zero ) {
            a[i] = 0;
            b[i] = 1;
          } else {
            a[i] = 1;
            b[i] = 0;
          }
          
          first_zero = false;
          break;
        case '2':
          if( first_zero ) {
            a[i] = 1;
            b[i] = 1;
          } else {
            a[i] = 2;
            b[i] = 0;
          }
          break;
      }
    }
    print_vector(a);
    print_vector(b);
  }
  return 0;
}
