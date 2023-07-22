#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cout<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cout<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"]\n":"|");

#define vx(x)            cout<<"{ " << #x << " = "<<x<<" }"<<endl;
#define vx2(x,y)         cout<<"{ " << #x << " = "<<x<<", " << #y << " = "<<y<<" }"<<endl;
#define vx3(x,y,z)       cout<<"{ " << #x << " = "<<x<<", " << #y << " = "<<y<<", " << #z << " = "<<z<<" }"<<endl;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    long long n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    long long min_by_element = a - b;
    long long max_by_element = a + b;
    long long min_sum_of_all = c - d;
    long long max_sum_of_all = c + d;
    long long min_sum_we_can_get = n * min_by_element;
    long long max_sum_we_can_get = n * max_by_element;

    if( min_sum_of_all <= min_sum_we_can_get && min_sum_we_can_get <= max_sum_of_all ) {
      cout << "Yes" << endl;
      continue;
    }
    if( max_sum_of_all <= max_sum_we_can_get && max_sum_we_can_get <= max_sum_of_all ) {
      cout << "Yes" << endl;
      continue;
    }
    if( min_sum_we_can_get > max_sum_of_all ) {
      cout << "No" << endl;
      continue;
    }
    if( max_sum_we_can_get < min_sum_of_all ) {
      cout << "No" << endl;
      continue;
    }
    cout << "Yes" << endl;
  }
  return 0;
}
