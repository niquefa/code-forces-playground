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

template<class T> string grow_to_size( T element , int size_to_get , const string& str_to_append = " " ){
  string answer = to_string(element);
  while( answer.size() < size_to_get )
    answer = str_to_append + answer;
  return answer;
}

template<class T> void print_vector(const vector<T>& c, const string& vector_name = "") {
  cerr << (!vector_name.empty() ? vector_name : "Vector : ") << "[ ";
  for(auto it = c.begin(); it != c.end(); ++it) {
    if (it != c.begin())
      cerr << " , ";
    cerr << *it;
  }
  cerr << " ] " << c.size() << " Elements." << endl;
}

template<class T> void print_set(const set<T>& c, const string& set_name = "") {
  cerr << (!set_name.empty() ? set_name : "   Set : ") << "{ ";
  for(auto it = c.begin(); it != c.end(); ++it) {
    if (it != c.begin())
      cerr << " , ";
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



#define vap(c)           cout<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cout<<(JJ==0?"[":"")<<c[JJ].first<<","<<c[JJ].second<<(JJ==(c).size()-1?"]\n":" | ");
#define vat(a,t)         cout<<#a << " :  ";for(int JJ=0;JJ<t;++JJ)cout<<(JJ==0?"[":"")<<a[JJ]<<(JJ==t-1?"]\n":",");
#define vaa(c)           cout<<#c << " :  "<<endl;for(int II=0;II<(c).size();++II)for(int JJ=0;JJ<(c[II]).size();++JJ)cout<<(JJ==0?"\t[":"")<<c[II][JJ]<<(JJ==(c[II]).size()-1?"]\n":"|");
#define vaat(c,F,C)      cout<<#c << " :  "<<endl;for(int II=0;II<F;++II)for(int JJ=0;JJ<C;++JJ)cout<<(JJ==0?"\t[":"")<<c[II][JJ]<<(JJ==C-1?"]\n":"|");

template<class T> map<T,int> get_frecuencies( const vector<T>& v ){map<T,int> ans;for( int i = 0; i < v.size(); ++ i )ans[v[i]]++;return ans;}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];

  map<int,int> f = get_frecuencies(a);
  print_map(f);

  vector<int> keys;
  for( auto it = f.begin(); it != f.end(); ++ it ) keys.push_back(it->first);

  vector<int> values;
  for( auto it = f.begin(); it != f.end(); ++ it ) values.push_back(it->second);

  print_vector(keys, "Keys  ");
  print_vector(values, "Values");

  bool factible = true;
  for( int i = 0; factible && i < keys.size(); ++ i )
    if( keys[i] != i )
      factible = false;

  for( int i = 0; factible && i < values.size() - 1; ++ i ) 
    if( values[i] < values[i+1] )
      factible = false;
  
  for( int i = 1; factible && i < values.size(); ++ i ) 
    if( values[i] > values[i-1] )
      factible = false;
  
  cout << (factible ? "YES" : "NO") << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  return 0;
}
