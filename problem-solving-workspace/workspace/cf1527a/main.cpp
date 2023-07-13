#include <bits/stdc++.h>
using namespace std;


int get_most_significant_bit(int num) {
    if (num <= 0) 
        return -1;
  
    int bit = 31;
    for( int bit = 31; bit >= 0; -- bit ) 
      if( num & (1 << bit) )
        return bit;
    
    return -1;
}
//bitwise operators
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n;
    cin >> n;
    int msb = get_most_significant_bit(n);
    cout << ((1<<(msb))-1) << endl;
  }
  return 0;
}
