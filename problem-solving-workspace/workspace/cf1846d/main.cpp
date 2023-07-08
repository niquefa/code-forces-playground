#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>
#include <sstream>
#include <utility>
#include <cctype>
#include <numeric>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <limits>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <functional>
#include <inttypes.h>
#include <fstream>
using namespace std;

#define EPS              (1e-10)

inline int cmp(double x, double y = 0, double tol = EPS) {return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;}
class P
{
    public:
    double x, y;
    P(double x_ = 0.0, double y_ = 0.0) : x(x_), y(y_) {}
    P operator +(const P &o) const {return P(x + o.x, y + o.y);}
    P operator -(const P &o) const {return P(x - o.x, y - o.y);}
    P operator *(const double &m) const {return P(m * x, m * y);}
    P operator /(const double &m) const {return P(x / m, y / m); }
    double operator *(const P &o) const {return x * o.x + y * o.y; }// Dot Product
    double operator ^(const P &o) const {return x * o.y - y * o.x; } // Cross Product
    int cmp(const P& o)const{if (int t = ::cmp(x, o.x)) return t;return ::cmp(y, o.y);}
    bool operator ==(const P &o) const {return cmp(o) == 0; }
    bool operator !=(const P &o) const {return cmp(o) != 0; }
    bool operator < (const P &o) const {return cmp(o) < 0; }
    double dist(const P &o) const {double d1 = x - o.x, d2 = y - o.y;return sqrt(d1 * d1 + d2 * d2);}
    friend ostream& operator <<(ostream &o, P p) {return o << "(" << p.x << ", " << p.y << ")";}
};


P Intersection(const P &p, const P &q,  const P &r, const P &s) {
  P a = q - p, b = s - r, c = P(p ^ q, r ^ s);
  return P(P(a.x, b.x) ^ c, P(a.y, b.y) ^ c) / (a ^ b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n;
    double d, h;
    cin >> n >> d >> h;
    vector<int> y(n);
    for( int i = 0; i < n; ++ i )
      cin >> y[i];
    sort(y.begin(), y.end());
    double ans = 0;
    vector<double> half;
    for( int i = 0; i < n; ++ i ) {
      if( i == n-1) { //last, add full area
        //ans += d * h / 2.0;
        half.push_back(d*h);
        continue;
      }
      double next_y = y[i+1];
      if( next_y >= y[i] + h ) { //next do not intersect
        half.push_back(d*h);
        //ans += d * h / 2.0;
        continue;
      }
      P p = P(-d/2.0,next_y);
      P q = P(d/2.0,next_y);
      P r = P(d/2.0,y[i]);
      P s = P(0,y[i]+h);      
      P inter = Intersection(p,q,r,s);
      double rectangle = inter.x * 2 *  (next_y-y[i]);
      double triangles = (d/2.0 - inter.x) * (next_y-y[i]);
      ans += rectangle + triangles;
    }
    double e = 0;
    for( int i = 0; i < half.size(); ++ i )
      e += half[i];
    std::cout << std::fixed << std::setprecision(12) << ans + e/2.0 << std::endl;
  }
  return 0;
}