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
#define vx4(x,y,z,w)     cout<<"{ " << #x << " = "<<x<<", " << #y << " = "<<y<<", " << #z << " = "<<z<<", " << #w << " = "<<w<<" }"<<endl;
#define vx5(x,y,z,w,q)   cout<<"{ " << #x << " = "<<x<<", " << #y << " = "<<y<<", " << #z << " = "<<z<<", " << #w << " = "<<w<<", " << #q << " = "<<q<<" }"<<endl;
#define vx6(x,y,z,w,q,p) cout<<"{ " << #x << " = "<<x<<", " << #y << " = "<<y<<", " << #z << " = "<<z<<", " << #w << " = "<<w<<", " << #q << " = "<<q<<", " << #p << " = "<<p<<" }"<<endl;

#define accum(c)         accumulate((c).begin(),(c).end(),0)

long long n, c;

long long get_used_cardboard( const vector<long long> &s, long long mid ) {
  long long current_cardboard_used = 0;
  for( int i = 0; i < s.size(); ++ i ) {
    current_cardboard_used += (s[i] + 2*mid) * (s[i] + 2*mid);
    if( current_cardboard_used > c) return -1;
  }
    
  return current_cardboard_used;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cin >> n >> c;
    vector<long long> s(n);
    for( int i = 0; i < n; ++ i) cin >> s[i];

    long long high = (long long)(sqrt(c) + 1);
    
    long long low = 0;
    long long answer = 0;
    while(true) { 
      long long mid = (high + low) / 2LL;

      long long current_cardboard_used = get_used_cardboard(s, mid);
      //vx4(low,high,mid,current_cardboard_used)
      if( current_cardboard_used == -1 ) {
        high = mid;
        continue;
      }

      if( current_cardboard_used == c ) {
        answer = mid;
        break;
      }
    
      if( current_cardboard_used <= c ) low = mid;
      else high = mid;
      if( high - low <= 1 ) break;
    }
    cout << answer << endl;

    //cout << endl;
  }
  return 0;
}
