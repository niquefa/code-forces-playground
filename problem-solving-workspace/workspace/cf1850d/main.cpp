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
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for( int i = 0; i < n; ++ i) cin >> a[i];

    if( n == 1 ) {
      cout << 0 << endl;
      continue;
    }

    sort(a.begin(), a.end());
    vector<long long> differences;
    for( int i = 1; i < n; ++ i ) differences.push_back(a[i] - a[i-1]);
    int max_subarray_length_of_at_most_k = 0;
    differences.push_back(10e11);

    int current_subarray_length = 0;
    for( int i = 0; i < differences.size(); ++ i ) {
      if( differences[i] <= k ) {
        current_subarray_length ++;
      } else {
        max_subarray_length_of_at_most_k = max( current_subarray_length, max_subarray_length_of_at_most_k);
        current_subarray_length = differences[i] <= k;
        //vx3(i, differences[i], max_subarray_length_of_at_most_k)
      }
    }

    
    // vx(current_test)
    // va(a)
    // va(differences)
    // vx3(n, k, max_subarray_length_of_at_most_k)
    cout << n - 1 - max_subarray_length_of_at_most_k << endl;
    //cout << endl;
  }
  return 0;
}
