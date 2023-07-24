#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");

#define vx(x)            cerr<<"{ " << #x << " = "<<x<<" }"<<endl;
#define vx2(x,y)         cerr<<"{ " << #x << " = "<<x<<", " << #y << " = "<<y<<" }"<<endl;
#define vx3(x,y,z)       cerr<<"{ " << #x << " = "<<x<<", " << #y << " = "<<y<<", " << #z << " = "<<z<<" }"<<endl;
#define vx4(x,y,z,w)     cerr<<"{ " << #x << " = "<<x<<", " << #y << " = "<<y<<", " << #z << " = "<<z<<", " << #w << " = "<<w<<" }"<<endl;
#define vx5(x,y,z,w,q)   cerr<<"{ " << #x << " = "<<x<<", " << #y << " = "<<y<<", " << #z << " = "<<z<<", " << #w << " = "<<w<<", " << #q << " = "<<q<<" }"<<endl;
#define vx6(x,y,z,w,q,p) cerr<<"{ " << #x << " = "<<x<<", " << #y << " = "<<y<<", " << #z << " = "<<z<<", " << #w << " = "<<w<<", " << #q << " = "<<q<<", " << #p << " = "<<p<<" }"<<endl;

void solve() {
  long long a, b, x, y, n;
  cin >> a >> b >> x >> y >> n;
  long long dx = a-x;
  long long dy = b-y;
  long long minimal_product = a * b;
  debug(a,b,x,y,n,dx,dy);
  if( dx + dy <= n ) {
    cout << x * y << endl;
    return;
  }
  if( a - n >= x ) {
    long long new_a = a - n;
    minimal_product = min(minimal_product, new_a * b);
    cerr << "0 > " << minimal_product << endl;
  }
  if( b - n >= y ) {
    long long new_b = b - n;
    minimal_product = min(minimal_product, a * new_b );
    cerr << "1 > " << minimal_product << endl;
  }
  if( n - dy >= 0 && a - (n-dy) >= x ) {
    long long new_a = a - (n-dy);
    minimal_product = min(minimal_product, new_a * y );
    cerr << "2 > " << minimal_product << endl;
  }
  if(n - dx >= 0 &&  b - (n-dx) >= y ) {
    long long new_b = b - (n-dx);
    minimal_product = min(minimal_product, x * new_b );
    cerr << "3 > " << minimal_product << endl;
  }

  cout << minimal_product << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  return 0;
}
