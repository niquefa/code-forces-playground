#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");

#define vap(c)           cerr <<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr <<(JJ==0?"[":"")<<c[JJ].first<<","<<c[JJ].second<<(JJ==(c).size()-1?"]\n":" | ");
#define vat(a,t)         cerr <<#a << " :  ";for(int JJ=0;JJ<t;++JJ)cerr <<(JJ==0?"[":"")<<a[JJ]<<(JJ==t-1?"]\n":",");
#define vaa(c)           cerr <<#c << " :  "<<endl;for(int II=0;II<(c).size();++II)for(int JJ=0;JJ<(c[II]).size();++JJ)cerr <<(JJ==0?"\t[":"")<<c[II][JJ]<<(JJ==(c[II]).size()-1?"]\n":"|");
#define vaat(c,F,C)      cerr <<#c << " :  "<<endl;for(int II=0;II<F;++II)for(int JJ=0;JJ<C;++JJ)cerr <<(JJ==0?"\t[":"")<<c[II][JJ]<<(JJ==C-1?"]\n":"|");


template<class T> string grow_to_size( T element , int size_to_get , const string& str_to_append = " " ){
  string answer = to_string(element);
  while( (int)answer.size() < size_to_get )answer = str_to_append + answer;
  return answer;
}

template<class T> void print_vector(const vector<T>& c, const string& vector_name = "") {
  cerr << (!vector_name.empty() ? vector_name : "Vector : ") << "[ ";
  for(auto it = c.begin(); it != c.end(); ++it) {
    if (it != c.begin()) cerr << " , ";
    cerr << *it;
  }
  cerr << " ] " << c.size() << " Elements." << endl;
}

template<class T> void print_set(const set<T>& c, const string& set_name = "") {
  cerr << (!set_name.empty() ? set_name : "   Set : ") << "{ ";
  for(auto it = c.begin(); it != c.end(); ++it) {
    if (it != c.begin()) cerr << " , ";
    cerr << *it;
  }
  cerr << " } " << c.size() << " Elements." << endl;
}

template<class K, class V> void print_map(const map<K, V>& m, const string& map_name = "") {
  cerr << (!map_name.empty() ? map_name : "   Map :") << " {" << endl;

  int max_key_length = 0;
  int max_value_length = 0;
  for(auto it = m.begin(); it != m.end(); ++it)
    max_key_length = max(max_key_length, (int)to_string(it->first).size()),
    max_value_length = max(max_value_length, (int)to_string(it->second).size());

  for(auto it = m.begin(); it != m.end(); ++it) {
    cerr << " " <<  grow_to_size(it->first, max_key_length + 1) << " -> " << grow_to_size(it->second, max_value_length + 1) << " ";
    for( int i = 0; i < it->second; ++ i ) cerr << "*";
    cerr << endl;
  }
  
  cerr << "} " << m.size() << " <K,V> pairs." << endl;
}

void print_char_map(const map<char, int>& m, const string& map_name = "") {
  cerr << (!map_name.empty() ? map_name : "CharMap:") << " {" << endl;
  int max_value_length = 0;
  for(auto it = m.begin(); it != m.end(); ++it)
    max_value_length = max(max_value_length, (int)to_string(it->second).size());

  for(auto it = m.begin(); it != m.end(); ++it) {
    cerr << " " << (it->first) << " -> " << grow_to_size(it->second, max_value_length + 1) << " ";
    for( int i = 0; i < it->second; ++ i ) cerr << "*";
    cerr << endl;
  }
  cerr << "} " << m.size() << " <char,int> pairs." << endl;
}

template<class K, class V> void print_set_of_pairs(const set<pair<K,V> >& c, const string& set_name = "") {
  cerr << (!set_name.empty() ? set_name : "PairSet: ") << "{ " << endl;

  int max_key_length = 0;
  int max_value_length = 0;
  for(auto it = c.begin(); it != c.end(); ++it)
    max_key_length = max(max_key_length, (int)to_string(it->first).size()),
    max_value_length = max(max_value_length, (int)to_string(it->second).size());

  for(auto it = c.begin(); it != c.end(); ++it) {
    if (it != c.begin())
      cerr << endl;
    cerr << " " <<  grow_to_size(it->first, max_key_length + 1) << " <>" << grow_to_size(it->second, max_value_length + 1);
  }
  cerr << endl << "} " << c.size() << " Pairs." << endl;
}

template<class T> void print_stack( const stack<T>& s, const string& stack_name = "" )
{
  stack<T> ss = s;
  deque<T> v;
  while( !ss.empty() ){
    v.push_front(ss.top());
    ss.pop();
  }
  cerr << "stack: ";
  va(v)
}
template<class T> void print_queue( const queue<T>& s )
{
  queue<T> ss = s;
  deque<T> v;
  while( !ss.empty() ){
    v.push_front(ss.front());
    ss.pop();
  }
  cerr << "queue: ";
  va(v)
}

#define sz               size()
#define fi(n)            for(int i=0;i<n;++i)
#define fj(n)            for(int j=0;j<n;++j)
#define fk(n)            for(int k=0;k<n;++k)
#define fij(n,m)         for(int i=0;i<n;++i)for(int j=0;j<m;++j)
#define fijk(a,b,c)      for(int i=0;i<a;++i)for(int j=0;j<b;++j)for(int k=0;k<c;++k)
#define ft(n)            for(int t=0;t<n;++t)
#define fturno(n)        for(int turno=0;turno<n;++turno)
#define fbit(n)          for(int bit=0;bit<n;++bit)
#define all(x)           (x).begin(),(x).end()
#define sr(x)            sort((x).begin(),(x).end());
#define pb               push_back
#define mp(x,y)          make_pair(x,y)
#define fs               first
#define sn               second
#define fora(i,a,b)      for(int i=a;i<=b;++i)
#define fore(it,c)       for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define fori(i,n)        for(int i=0;i<n;++i)
#define foro(i,M,m)      for(int i=M;i>=m;--i)
#define foru(i,n)        for(int i=1;i<=n;++i)
#define accum(c)         accumulate((c).begin(),(c).end(),0)
#define countx(c,x)      count((c).begin(),(c).end(),x)
#define EPS              (1e-10)
#define fall(c,f)        for_each((c).begin(),(c).end(),f);
#define haschar(s,car)   (s.find(car)!=string::npos)
#define iminel(c)        ((min_element((c).begin(),(c).end()))-(c).begin())
#define iminelf(c,fun)   ((min_element((c).begin(),(c).end(),fun))-(c).begin())
#define incontainer(c,x) ((c).find(x)!=(c).end())
#define invector(c,x)    (find((c).begin(),(c).end(),x)!=(c).end())
#define isconsonant(car) (string("bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ").find(car)!=string::npos)
#define isleap(a)        (((a%4==0)&&(a%100!=0))||(a%400==0))
#define isvowel(car)     (string("aeiouAEIOU").find(car)!=string::npos)
#define ispow2(v)        (!(v & (v - 1)) && v)//is power of 2? 0 is not considered power of 2
#define ispow22(v)       ((v & (v - 1)) == 0) //is power of 2? 0 is considered power of 2
#define maxel(c)         (*max_element((c).begin(),(c).end()))
#define maxelf(c,fun)    (*max_element((c).begin(),(c).end(),fun))
#define minel(c)         (*min_element((c).begin(),(c).end()))
#define minelf(c,fun)    (*min_element((c).begin(),(c).end(),fun))
#define mset(a,x)        memset(a,x,sizeof(a));
#define ok(r,c,R,C)      ( r>=0 && c>=0 && c<C && r<R )
#define pnext(c)         next_permutation((c).begin(),(c).end())
#define pprev(c)         prev_permutation((c).begin(),(c).end())
#define rev(x)           reverse((x).begin(),(x).end());
#define rsor(x)          sort((x).rbegin(),(x).rend());
#define swapd(a,b)       (((a)^=(b)),((b)^=(a)),((a)^=(b)));
#define to_lower(s)      transform((s).begin(),(s).end(),(s).begin(),::tolower);
#define to_upper(s)      transform((s).begin(),(s).end(),(s).begin(),::toupper);
#define zero(a)          memset(a,0,sizeof(a));
#define mone(a)          memset(a,-1,sizeof(a));
#define allf(a)          memset(a,false,sizeof(a));

bool equalsd (double a, double b) { return abs(a-b) < (1e-9) ;}
void unik( vector <double> &v ){sort(v.begin(),v.end());vector <double>::iterator it;it = unique((v).begin(),(v).end(),equalsd);v.resize(it-v.begin());}
void unik( vector <int> &v ){sort(v.begin(),v.end());vector <int>::iterator it;it = unique((v).begin(),(v).end());v.resize(it-v.begin());}
void unik( vector <string> &v ){sort(v.begin(),v.end());vector <string>::iterator it;it = unique((v).begin(),(v).end());v.resize(it-v.begin());}
void unik( vector <char> &v ){sort(v.begin(),v.end());vector <char>::iterator it;it = unique((v).begin(),(v).end());v.resize(it-v.begin());}
void unik( vector <long long> &v ){sort(v.begin(),v.end());vector <long long>::iterator it;it = unique((v).begin(),(v).end());v.resize(it-v.begin());}

template<class T> int find_first( vector< T >& v, T o ){   for( int i = 0; i < v.size(); ++ i )if( v[i] == o )return i; return -1;}
template<class T> int find_last( vector< T >& v, T o ){   for( int i = v.size()-1; i >= 0 ; -- i )if( v[i] == o )return i; return -1;}
template<class T> pair<int,T> find_and_remove_first( vector< T >& v, T o ){for( int i = 0; i < v.size(); ++ i )if( v[i] == o ){pair<int,T> ret = make_pair(i,v[i]);v.erase(i+v.begin());return ret;} return make_pair(-1,o);}
template<class T> pair<int,T> find_and_remove_last( vector< T >& v, T o ){for( int i = v.size()-1; i >= 0 ; -- i )if( v[i] == o ){pair<int,T> ret = make_pair(i,v[i]);v.erase(i+v.begin());return ret;}return make_pair(-1,o);}

bool isPrime( long long n){if (n < 0) return isPrime(-n);if (n < 5 || n % 2 == 0 || n % 3 == 0) return (n == 2 || n == 3);long long maxP = ( long long )(sqrt(n) + 2);for (long  p = 5; p < maxP; p += 6)if (n % p == 0 || n % (p+2) == 0) return false;return true;}
template<class T> T gcd(T a,T b) {if (a<0) a=-a;if (b<0) b=-b;return (b==0)?a:gcd(b,a%b);}
template<class T> T lcm(T a,T b) {return (a/gcd(a,b))*b;}

template<class T> inline T sqr (T b){return(b*b);}
template<class T,class E> T fpow( T b , E e){if(e<0) return 1/fpow(b,-e);if(e==0)return 1;else if(e%2==0)return sqr(fpow(b,e/2));else return b*fpow(b,e-1);}
unsigned long long fmp(unsigned long long b, unsigned long long e, unsigned long long m){unsigned long long r = 1;while (e > 0) {if ((e & 1) == 1) r = (r * b) % m;e >>= 1;b = (b * b) % m;}return r;}

//unik(a);unik(b); Could be needed if repeated elements. If repeated works as multiset.
//set_intersection,set_union,set_symmetric_difference
vector<int> ocd(vector<int>& a,vector<int>& b){  vector<int> c(a.size()+b.size());   sort(a.begin(),a.end());   sort(b.begin(),b.end());c.resize(int(set_difference(a.begin(),a.end(),b.begin(),b.end(),c.begin())-c.begin()));return c;}

unsigned long long toi64(string s) {unsigned long long v;istringstream sin(s);sin>>v;return v;}
template<class T> string tostring(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> int toint( T s ) {int v;istringstream sin( tostring(s) );sin>>v;return v;}
inline int s2i( string a ){return atoi( a.c_str() );}
double todouble(string s) {double v;istringstream sin(s);sin>>v;return v;}

template<class T> int sumdig( T n ){int ret = 0;if( n < 0 ) return sumdig(-n);while(n>0)ret += n%10,n /= 10;return ret;}
inline unsigned long int todecimal( string n , int b ){return strtoul(n.c_str(),NULL,b);}
const string DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
long long todec(string n, int b){long long r = 0,m = 1;for (int i = n.length() - 1; i >= 0; --i)r += (long long)DIGITS.find(n[i]) * m,m *= (long long)b;return r;}
template<class T> string tobase(T number, int base, const int& length){if( number == 0 )return "0";string r = "";while (number != 0)r = tostring (DIGITS[number % base]) + r,number /= base;return r;}

template<class T> vector<T> strtovt(string s) { vector<T> ret;istringstream f(s); T tmp; while (f >> tmp) ret.push_back(tmp);return ret;}
vector<string> tokenize(const string& str, const string& d = " "){vector <string> t;int up  = str.find_first_not_of(d, 0);int pos = str.find_first_of(d, up);while (string::npos != pos || string::npos != up){t.push_back(str.substr(up, pos - up));up = str.find_first_not_of(d, pos);pos = str.find_first_of(d, up);}return t;}
vector<int> splittoint( const string& s, const string& delim =" " ){vector <string> tok = tokenize(s,delim);vector <int> res;for(int i=0;i<tok.size();++i)res.push_back( atoi( tok[i].c_str() ) );return res;}

long long nck[500][500];
long long nCk( const int& n , const int& k ){if( k == 0 || k == n )return 1;if( k < 0 || k > n )return 0; if( nck[n][k] != -1 ) return nck[n][k];return nck[n][k] = nCk( n-1 , k ) + nCk( n-1 , k-1 );}
template<class T> long long factorial( const T& n /*hasta 20*/ ){long long f = 1L;for( long long i = 2; i <= n ;++ i )f *= (long long)i;return f;}
void trim( string& c ){if( c.size() == 0 ) return;int i , p = -1 , q = -1;for( i = 0; i < c.size(); ++ i )if( int(c[i])%255 > int(' ') ){p = i;break;}for( i = c.size()-1; i >= 0; -- i )if( int(c[i])%255 > int(' ') ){q = i;break;}c = p == -1 ? "" : c.substr(p,q-p+1);}
inline string trimm( string c ){string s(c);trim(s);return s;}

const int dr[]  = {-1,0,0,1};
const int dc[]  = {0,-1,1,0};
const int drd[] = {-1,-1,1,1};
const int dcd[] = {-1,1,-1,1};
const int dr8[] = {-1,-1,-1  ,  0,0  ,   1,1,1};
const int dc8[] = {-1, 0, 1  , -1,1  ,  -1,0,1};
const int drc[] = {-2,-2 , -1,-1 ,  1,1 ,  2,2};
const int dcc[] = {-1, 1 , -2, 2 , -2,2 , -1,1};
const string ABC =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const string ABCm = "abcdefghijklmnopqrstuvwxyz0123456789";
int months[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
const int oo = 1<<30;
const int moo = -(1<<30);
const double PI = 3.1415926535897932384626433832795;
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

template<class T> int countbit(T n) {return (n==0)?0:(1+countbit(n&(n-1)));}
template<class T> T lowbit(T n) {return (n^(n-1))&n;}//2^(posici\F3n del bit encendido menos significativo)
template<class T> inline T union_b( const T& a , const T& b ){ return a|b;}
template<class T> inline T intersection_b( const T& a , const T& b ){return a & b;}
template<class T> inline T subtraction_b( const T& a , const T& b ){return a & ~b;}

inline int negation_b( const int& a ){;return ((1<<29)-1) ^ a;}
inline int set_b( const int& mask, const int& bit ){return mask | (1 << bit);}
inline int clear_b( const int& mask, const int& bit ){return mask & (~(1 << bit));}
inline bool is_on( const int& mask, const int& bit ){return (mask & (1 << bit)) != 0;}
inline bool is_off( const int& mask, const int& bit ){return (mask & (1 << bit)) == 0;}

inline long long negation_b( const long long& a ){;return ((1LL<<62)-1) ^ a;}
inline long long set_b( const long long& mask, const int& bit ){return mask | (1LL << bit);}
inline long long clear_b( const long long& mask, const int& bit ){return mask & (~(1LL << bit));}
inline bool is_on( const long long& mask, const int& bit ){return (mask & (1LL << bit)) != 0LL;}
inline bool is_off( const long long& mask, const int& bit ){return (mask & (1LL << bit)) == 0LL;}


#define	b_is_proper_subset_of_a(a,b)      (  (a!=b) && ( (a&b)==b )  )
#define	b_is_subset_of_a(a,b)             ( (a&b)==b )
                                                //For     10011010100010000 = 79120
#define lzeros(n)        __builtin_clz(n)       //0 to the left   >> 15
#define ones(n)          __builtin_popcount(n)  //ones            >>  6
#define rzeros(n)        __builtin_ctz(n)       //0 to the right  >>  4
#define lzerosL(n)       __builtin_clzll(n)     //0 to the left   >> 47
#define onesL(n)         __builtin_popcountll(n)//ones            >>  6
#define rzerosL(n)       __builtin_ctzll(n)     //0 to the right  >>  4
#define two_to(n)        (1<<(n))
#define two_toll(n)      ((1(unsigned long long))<<(n))
#define contains(s,x)    ((s&(1<<(x)))>0)                        //s contains x?, For s=...1010001[2], x=3[10], true, x=2, false
#define containsl(s,x)   ((s&((1(unsigned long long))<<(n)))>0)  //s contains x?,

vector<vector<bool> > get_adj_matrix( const vector<string>& m ){vector<vector<bool> > ans;for( int i = 0; i < m.size(); ++ i ){vector<bool> v;for( int j = 0; j < m[i].size(); ++ j )v.push_back(m[i][j] == 'Y');ans.push_back(v);}return ans;}

template<class T> inline T fmax( const T& a , const T& b ){return a > b ? a: b;}
template<class T> inline T fmax( const T& a , const T& b , const T& c ){return a > b && a > c ? a: b > c ? b : c;}
template<class T> inline T fmax( const T& a , const T& b , const T& c ,const T& d ){return a > b && a > c && a > d ? a: b > c && b > d ? b : c > d ? c : d ;}

template<class T> inline T fmin( const T& a , const T& b ){return a < b ? a: b;}
template<class T> inline T fmin( const T& a , const T& b , const T& c ){return a < b && a < c ? a: b < c ? b : c;}
template<class T> inline T fmin( const T& a , const T& b , const T& c ,const T& d ){return a < b && a < c && a < d ? a: b < c && b < d ? b : c < d ? c : d ;}

template<class T> inline void tmax( T& ans , const T& tmp ){ if( tmp > ans ) ans = tmp;}
template<class T> inline void tmin( T& ans , const T& tmp ){ if( tmp < ans ) ans = tmp;}

template<class T> inline void tmax( T& ans , const T& a , const T& b ){ if( a > b && a > ans ) ans = a; else if( b > a && b > ans ) ans = b; }
template<class T> inline void tmin( T& ans , const T& a , const T& b ){ if( a < b && a < ans ) ans = a; else if( b < a && b < ans ) ans = b; }

int find_first_char(const string& str, char c) {
    auto it = find(str.begin(), str.end(), c);
    return it == str.end() ? - 1 : distance(str.begin(), it);
}
int find_last_char(const string& str, char c) {
    auto it = find_end(str.begin(), str.end(), &c, &c + 1);
    return it == str.end() ? - 1 : distance(str.begin(), it);
}

template<typename T> int find_first_element(const vector<T>& v, T element) {
    auto it = find(v.begin(), v.end(), element);
    return it == v.end() ? - 1 : distance(v.begin(), it);
}

template<typename T> int find_last_element(const vector<T>& v, T element) {
    auto it = find_end(v.begin(), v.end(), &element, &element + 1);
    return it == v.end() ? - 1 : distance(v.begin(), it);
}

int find_first_substring(const string& str, const string& substr) {
    size_t found = str.find(substr);
    return found != string::npos ? static_cast<int>(found) : -1; 
}

int find_last_substring(const string& str, const string& substr) {
    size_t found = str.rfind(substr);
    return found != string::npos ? static_cast<int>(found) : -1; 
}

template <typename T> int index_max_element(const vector<T>& vec) {
    return vec.empty() ? -1 : distance(vec.begin(), max_element(vec.begin(), vec.end()));
}

template <typename T> int index_min_element(const vector<T>& vec) {
    return vec.empty() ? -1 : distance(vec.begin(), min_element(vec.begin(), vec.end()));
}

//printf("%.25lf\n",);
////////////////////////////////////////////////////////////////////////////////

//g++ hello.cc && ./a.out < t.in

void print_solution( const vector<int>& solution_vector ) {
  for( int i = 0; i < solution_vector.size(); ++ i) 
    cout << (i > 0 ? " " : "") << solution_vector[i];
  cout << endl;
}

template<class K, class V> set<K> key_set(const map<K, V>& m) {
    set<K> keys;
    for (const auto& pair : m) 
        keys.insert(pair.first);
    return keys;
}

template<class T> map<T,int> get_frequencies( const vector<T>& v ){map<T,int> ans;for( int i = 0; i < v.size(); ++ i )ans[v[i]]++;return ans;}

map<char,int> get_char_frequencies( const string& v ){map<char,int> ans;for( int i = 0; i < v.size(); ++ i )ans[v[i]]++;return ans;}

template<typename T>T iceil(T n, T d) {
  if (d == 0) throw runtime_error("Division by zero!");
  if (n < 0 || d < 0) return (n + ((d > 0) ? 0 : (d + 1))) / d;
  return (n + d - 1) / d;
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
class Solution {
public:
    int countPairs(vector<int>& a, int t) {
      int ans = 0;
        for( int i = 0; i < a.size(); ++ i ) {
          for( int j = i+1; j < a.size(); ++ j ) {
            if( (a[i] + a[j]) < t ) {
              ans++;
            }
          }
        }
        return ans;
    }
};
void solve() {
  int n, target;
  cin >> n >> target;
  vector<int> a(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];
  
  cout << Solution().countPairs(a, target) << endl;
}
