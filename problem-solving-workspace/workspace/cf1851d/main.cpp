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

vector<long long> get_diff( const vector<long long>& a ) {
  vector<long long> differences;
  for( int i = 1; i < a.size(); ++ i) {
    differences.push_back(abs(a[i] - a[i-1]));
  }
  return differences;
}
bool is_permutation( const vector<long long> a ) {
  for( int i = 0; i < a.size(); ++ i ) {
    if( a[i] != i+1 ) return false;
  }

  return true;
}
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n-1);
  vector<long long> c(n);
  for( int i = 0; i < n-1; ++ i) 
    cin >> a[i];
  if( is_permutation(a) ) {
    cout << "NO" << endl;
    return;
  }
  for( int i = 0; i < n; ++ i) 
    c[i] = i+1;

  vector<long long> prefix_sum_of_c;
  prefix_sum_of_c.push_back(0);
  for( int i = 0; i < n; ++ i) {
    prefix_sum_of_c.push_back(prefix_sum_of_c.back() + c[i]);
  }

  vector<long long> differences = get_diff(a);
  //print_vector(a," a ");
  //print_vector(differences," d ");
  set<long long> set_diff(differences.begin(),differences.end());
  if( set_diff.size() != n-1 && set_diff.size() != n-2) {
    cout << "NO" << endl;
    return;
  }
  for( int i = 0; i < differences.size(); ++ i ) {
    if( differences[i] <= 0 || differences[i] > 3*n - 3 - n ) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
  // print_vector(c, " c ");
  // print_vector(prefix_sum_of_c, "psc");
  // cout << (a.size() ? "YES" : "NO") << endl;
}

vector<long long> get_prefix_sum( const vector<long long>& permutation ) {
  vector<long long> prefix_sum;
  prefix_sum.push_back(0);
  for( int i = 0; i < permutation.size(); ++ i ) prefix_sum.push_back(prefix_sum.back() + permutation[i]);
  prefix_sum.erase(prefix_sum.begin());
  return prefix_sum;
}

void precompute() {
  int n = 6;
  vector<long long> permutation;
  for( int i = 1; i <= n; ++ i ) permutation.push_back(i);
  do {
    print_vector(permutation,"\n P ");
    vector<long long> ps = get_prefix_sum(permutation);
    print_vector(ps,"Ps ");
    for( int i = 0; i < n; ++ i ) {
      vector<long long> sub_ps;
      for( int j = 0; j < n; ++ j ) {
        if( j == i ) continue;
        sub_ps.push_back(ps[j]);
      }
      //debug(i);
      print_vector(sub_ps,"sub_ps");
      vector<long long> diff = get_diff(sub_ps);
      print_vector(diff,"diff");
    }
    
    
  } while( next_permutation(permutation.begin(),permutation.end()) );
}
int main() {
  auto start_execution_time = std::chrono::high_resolution_clock::now();
  precompute();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    //cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = std::chrono::high_resolution_clock::now();

  chrono::duration<double, std::milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
