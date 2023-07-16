#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    int n;
    cin >> n;
    if( n == 2 ) {
      cout << "2 1" << endl;
      continue;
    }
    if( n == 2 ) {
      cout << "3 1 2" << endl;
      continue;
    }
    int answer = 0;
    if( n % 2 == 0 ) {
      for( int i = 0; i < n; i += 2 ) 
        cout << i + 2 << " " << i + 1 << " ";
      
    } else {
      cout << "3 1 2 ";
      for( int i = 4; i < n; i += 2 ) 
        cout << i + 1 << " " << i << " ";
    }
    cout << endl;
  }
  return 0;
}
