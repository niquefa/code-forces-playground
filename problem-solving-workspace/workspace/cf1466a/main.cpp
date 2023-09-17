#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");
const double EPS = 1e-9;
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

long long twiceTheTriangleArea(P p1, P p2, P p3) {
    return (long long)abs(p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - p1.y*p2.x - p2.y*p3.x - p3.y*p1.x);
}
void solve();
int main() {
  auto start_execution_time = chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
void solve() {
  int n;
  cin >> n;
  vector<long long> x(n);
  for( int i = 0; i < n; ++ i) cin >> x[i];
  set<long long> s;
  for( int i = 0; i < n; ++ i ) {
    double x0 = x[i];
    for( int j = i+1; j < n; ++ j ) {
      double x1 = x[j];
      P p1(x0, 0), p2(x1, 0), p3(0, 1);
      s.insert(twiceTheTriangleArea(p1, p2, p3));
    }
  }
  cout << s.size() << endl;
}
