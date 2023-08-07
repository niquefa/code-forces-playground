#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");

#define vap(c)           cout<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cout<<(JJ==0?"[":"")<<c[JJ].first<<","<<c[JJ].second<<(JJ==(c).size()-1?"]\n":" | ");
#define vat(a,t)         cout<<#a << " :  ";for(int JJ=0;JJ<t;++JJ)cout<<(JJ==0?"[":"")<<a[JJ]<<(JJ==t-1?"]\n":",");
#define vaa(c)           cout<<#c << " :  "<<endl;for(int II=0;II<(c).size();++II)for(int JJ=0;JJ<(c[II]).size();++JJ)cout<<(JJ==0?"\t[":"")<<c[II][JJ]<<(JJ==(c[II]).size()-1?"]\n":"|");
#define vaat(c,F,C)      cout<<#c << " :  "<<endl;for(int II=0;II<F;++II)for(int JJ=0;JJ<C;++JJ)cout<<(JJ==0?"\t[":"")<<c[II][JJ]<<(JJ==C-1?"]\n":"|");


#define vx(x)            cerr<<"{ " << #x << " = "<<x<<" }"<<endl;
#define vx2(x,y)         cerr<<"{ " << #x << " = "<<x<<", " << #y << " = "<<y<<" }"<<endl;
#define vx3(x,y,z)       cerr<<"{ " << #x << " = "<<x<<", " << #y << " = "<<y<<", " << #z << " = "<<z<<" }"<<endl;
#define vx4(x,y,z,w)     cerr<<"{ " << #x << " = "<<x<<", " << #y << " = "<<y<<", " << #z << " = "<<z<<", " << #w << " = "<<w<<" }"<<endl;
#define vx5(x,y,z,w,q)   cerr<<"{ " << #x << " = "<<x<<", " << #y << " = "<<y<<", " << #z << " = "<<z<<", " << #w << " = "<<w<<", " << #q << " = "<<q<<" }"<<endl;
#define vx6(x,y,z,w,q,p) cerr<<"{ " << #x << " = "<<x<<", " << #y << " = "<<y<<", " << #z << " = "<<z<<", " << #w << " = "<<w<<", " << #q << " = "<<q<<", " << #p << " = "<<p<<" }"<<endl;

template<class T> string grow_to_size( T element , int size_to_get , const string& str_to_append = " " ){
  string answer = to_string(element);
  while( (int)answer.size() < size_to_get )
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

void print_solution( const vector<long long>& solution_vector ) {
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

template<class T> map<T,int> get_frecuencies( const vector<T>& v ){map<T,int> ans;for( int i = 0; i < v.size(); ++ i )ans[v[i]]++;return ans;}

void solve();
int main() {
  auto start_execution_time = chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    //cerr << "\nTest case " << current_test << endl;
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
  int m = (n * (n-1))/2;
  debug(m,n);
  vector<long long> b(m);
  for( int i = 0; i < m; ++ i) cin >> b[i];
  if( b.size() == 1 ){
    cout << b[0] << " " << b[0] << endl;
    return;
  }
  set<long long> keys(b.begin(), b.end());
  if( keys.size() == 1 ) {
    for( int i = 0; i < n; ++ i ) 
      cout << b[0] << " ";
    cout << endl;
    return;
  }
  sort(b.begin(), b.end());
  //print_vector(b);
  vector<long long> a;
  map<long long,int> f = get_frecuencies(b);
  //print_map(f);
  vector<long long> keys_vector(keys.begin(), keys.end());
  //print_vector(keys_vector,"Keys");
  for( int repetitions = n-1; repetitions >= 1; -- repetitions ) {
    for( auto key : keys_vector ) {
      if( f[key] >= repetitions ) {
        a.push_back(key);
        f[key] -= repetitions;
        break;
      }
    }
    //debug(repetitions);
    //print_vector(a);
  }
  a.push_back(1000000000LL);
  assert(a.size() == n);
  if (a.size() != n) {
    cout << a[-b.size()] << endl;
    return;
  }
  print_solution(a);  
}
