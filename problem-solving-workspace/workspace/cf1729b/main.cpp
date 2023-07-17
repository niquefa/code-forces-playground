#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


const string decode = "_abcdefghijklmnopqrstuvwxyz0123456789";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    int n;
    string code;
    cin >> n >> code;
    string decoded_string = "";
    
    for( int i = n-1; i >= 0 ;) {
      int digit = code[i] - '0';
      if( digit == 0 ) {
        int a = code[i-2] - '0';
        int b = code[i-1] - '0';
        int index = a*10 + b;
        decoded_string += decode[index];
        i = i - 3;
        continue;
      } else {
        decoded_string += decode[digit];
        --i;
      }
      
    }
    reverse(decoded_string.begin(), decoded_string.end());
    cout << decoded_string << endl;
  }
  return 0;
}
