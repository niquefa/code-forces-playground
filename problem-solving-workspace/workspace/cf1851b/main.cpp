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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];
  
  vector<int> even_positions;
  vector<int> odd_positions;
  vector<int> even;
  vector<int> odd;
  
  for( int i = 0; i < n; ++ i) {
    if( a[i] % 2 == 0 ){
      even.push_back(a[i]);
      even_positions.push_back(i);
    } else{
      odd.push_back(a[i]);
      odd_positions.push_back(i);
    }
  }
  sort(even.begin(), even.end());
  sort(odd.begin(), odd.end());
  vector<int> final_vector;
  int index_even_positions = 0;
  int index_odd_positions = 0;
  // print_vector(a);
  // print_vector(even_positions,"Even pos");
  // print_vector(even,"EVEN");
  // print_vector(odd_positions, "Odd pos");
  // print_vector(odd,"ODDS");
  for( int i = 0; i < n; ++ i) {
    //debug(i, index_even_positions, index_odd_positions);
    if( index_even_positions == even_positions.size() ) {
      final_vector.push_back(odd[index_odd_positions]);
      index_odd_positions++;
      continue;
    }
    if( index_odd_positions == odd_positions.size() ) {
      final_vector.push_back(even[index_even_positions]);
      index_even_positions++;
      continue;
    }
    int next_odd_index = odd_positions[index_odd_positions];
    int next_even_index = even_positions[index_even_positions];
    //debug(next_odd_index, next_even_index);

    if( next_odd_index < next_even_index ) {
      final_vector.push_back(odd[index_odd_positions]);
      index_odd_positions++;
    } else {
      final_vector.push_back(even[index_even_positions]);
      index_even_positions++;
    }
  }

  //print_vector(final_vector);
  bool sorted = true;

  for( int i = 1; i < final_vector.size(); ++ i ) {
    if( final_vector[i] < final_vector[i-1] ) {
      sorted = false;
      break;
    }
  }

  cout << (sorted ? "YES" : "NO") << endl;
}

int main() {
  auto start_execution_time = std::chrono::high_resolution_clock::now();

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
