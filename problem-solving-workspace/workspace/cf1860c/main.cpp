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

class FenwickTree {
public:
    FenwickTree(int n): bit(n + 1, 0) {}

    // Sum of the range [0, i]
    int query(int i) const {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += bit[i];
        }
        return sum;
    }

    // Increment position i by delta
    void update(int i, int delta) {
        for (; i < bit.size(); i += i & -i) {
            bit[i] += delta;
        }
    }

private:
    vector<int> bit;
};

vector<int> compute_lower_counts(const vector<int>& p) {
    int n = p.size();
    FenwickTree tree(n);
    vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        b[i] = tree.query(p[i]);
        tree.update(p[i] + 1, 1);
    }

    return b;
}
void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  for( int i = 0; i < n; ++ i) cin >> p[i];
  // vector<int> b = compute_lower_counts(p);
  // print_vector(b);
  // int ans = 0;
  // for( int i = 0; i < n; ++ i )
  //   if( b[i] == 2 ) 
  //     ans ++;
  // cout << ans << endl;

  int min_up_to_before_pi = n+1;
  int min_up_to_pi = n+1;
  int alice_wins = 0;
  for (int i = 0; i < n; i++) {
    bool bob_wins = false;
    if (p[i] < min_up_to_pi) {
      min_up_to_pi = p[i];
      bob_wins = true;
    } else {
      bob_wins = (min_up_to_before_pi < p[i]);
    }
    if (!bob_wins) {
      ++alice_wins;
      min_up_to_before_pi = min(min_up_to_before_pi, p[i]);
    }
  }
  cout << alice_wins << endl;
}
