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
  string s;
  cin >> n >> s;
  map<char,int> fa;
  map<char,int> fb;
  int ans = fb.size();
  for( char c : s ) 
    fb[c] ++;
  for( char c : s ){
    fb[c]--;
    if( fb[c] == 0 ) {
      fb.erase(c);
    }
    fa[c]++;
    if( fa.size() == fb.size() ) {
      ans = max(ans, (int)fa.size()+(int)fb.size() );
    }
  }

  cout << ans << endl;
}
