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



template<class T> T gcd(T a,T b) {if (a<0) a=-a;if (b<0) b=-b;return (b==0)?a:gcd(b,a%b);}
template<class T> T lcm(T a,T b) {return (a/gcd(a,b))*b;}

vector<int> get_d( const vector<int>& p ) {
  vector<int> d;
  int n = p.size();
  for( int i = 0; i < n; ++ i ) {
    int ii = (i+1)%n;
    int di = gcd(p[i],p[ii]);
    d.push_back(di);
  }
  return d;
}
int score( const vector<int>& p ) {
  int n = p.size();
  vector<int> d = get_d(p); 
  //print_vector(d);
  set<int> s(d.begin(),d.end());
  return s.size();
}
int best_score[] = {-1,-1,1,1,2,2,3,3,4,4,5,5,6,6};
void brute_force(int n) {
  vector<int> p(n);
  iota(p.begin(), p.end(), 1);
  va(p);
  vector<int> best_p(p.begin(), p.end());
  int max_score = score(best_p);
  do {
    int s = score(p);
    //print_vector(p);
    //debug("score ", s);
    //cerr << endl;

    if (s >= max_score) {
      max_score = s;
      best_p = p;
    }
    if( s == best_score[n] ) {
      //print_vector(p);
      //cerr << endl;
    }
  } while (next_permutation(p.begin(), p.end()));
  print_vector(best_p);
  print_vector(get_d(best_p));
  vx(max_score);
  cerr << endl;
}
const int MAX = 200010;
bool used[MAX];
bool is_prime[MAX];

void fill_primes() {
    memset(is_prime, true, sizeof(is_prime));

    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i * i < MAX; i++) {
        if(is_prime[i]) {
            for(int j = i * i; j < MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void solve();
int main() {
  auto start_execution_time = chrono::high_resolution_clock::now();
  // vector<int> pt = {1,2,3,6,4,5,7};
  // score(pt);


  // for( int n = 10; n <= 15; ++ n ) {
  //   debug("For n ", n, "Best score is ", best_score[n]);
  //   brute_force(n);
  // }
  fill_primes();
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
void print_solution( const vector<int>& solution_vector ) {
  for( int i = 0; i < solution_vector.size(); ++ i) 
    cout << (i > 0 ? " " : "") << solution_vector[i];
  //cout << " => " << solution_vector.size() << " score " << score(solution_vector);
  cout << endl;
}

#define incontainer(c,x) ((c).find(x)!=(c).end())

void solve() {
  int n;
  cin >> n;
  vector<int> solution;
  set<int> used;
  for( int i = 1; i <= n; ++ i ) {
    if( incontainer(used,i) )
      continue;
    solution.push_back(i);
    used.insert(i);
    for( int multiple = 2*i; multiple <= n; multiple *=2 ) {
      if( incontainer(used,multiple) )
        continue;
      solution.push_back(multiple);
      used.insert(multiple);
    }
  }

  print_solution(solution);
}
