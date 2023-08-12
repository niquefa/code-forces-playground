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
long long get_cost(const vector<int>& permutation) {
  long long result = 0;
  long long bestJValue = 0;
  for(vector<int>::size_type i = 0; i < permutation.size(); ++i) {
    result += (long long)permutation[i] * (i+1);
    if( permutation[i]*((long long)i+1) > bestJValue ) {
      bestJValue = permutation[i]*(i+1);
    }
  }
  return result - bestJValue;
} 
void brute_force() {
  for( int n = 1; n <= 20; ++ n ) {
    long long best_cost = 0;
    vector<int> permutation(n);
    iota(permutation.begin(), permutation.end(), 1);
    vector<int> best_permutation;
    do {
      long long current_cost = get_cost(permutation);
      if( current_cost > best_cost ) {
        best_cost = current_cost;
        best_permutation = permutation;
      }
    } while(next_permutation(permutation.begin(), permutation.end()));
    print_vector(best_permutation, "Best permutation");
    debug(n, best_cost);
    cerr << endl;cerr << endl;cerr << endl;
  }
}
int main() {
  auto start_execution_time = chrono::high_resolution_clock::now();
  //brute_force();
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
long long get_answer_with_brute_force(int n)
{
  long long best_cost = 0;
  vector<int> permutation(n);
  iota(permutation.begin(), permutation.end(), 1);
  vector<int> best_permutation;
  do {
    long long current_cost = get_cost(permutation);
    if( current_cost > best_cost ) {
      best_cost = current_cost;
      best_permutation = permutation;
    }
  } while(next_permutation(permutation.begin(), permutation.end()));
  return best_cost;
}
void solve() {
  int n;
  cin >> n;
  if( n <= 9 ) {
    cout << get_answer_with_brute_force(n) << endl;
    return;
  }
  long long best_cost = 0;
  vector<int> permutation(n);
  for( int up_to = 1; up_to <= n; ++up_to ) {
    int index = 0;
    for( int i = 1; i <= up_to; ++i ) {
      permutation[index++] = i;
    }
    int going_down = n;
    for( int i = up_to+1; i <= n; ++i ) {
      permutation[index++] = going_down--;
    }

    long long current_cost = get_cost(permutation);
    if( current_cost > best_cost ) {
      best_cost = current_cost;
    }
  }
  
  
  cout << best_cost << endl;
}
