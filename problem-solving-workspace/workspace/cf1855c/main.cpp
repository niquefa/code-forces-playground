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
void solve();
int main() {
  auto start_execution_time = std::chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = std::chrono::high_resolution_clock::now();

  chrono::duration<double, std::milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
bool is_non_decreasing( const vector<int>& a ) {
  for( int i = 1; i < a.size(); ++ i ) if( a[i] < a[i - 1] ) return false;
  return true;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];
  //debug(n);
  //print_vector(a);

  if( is_non_decreasing(a) ) {
    //print_vector(a,"Already Non Decreasing");
    cout << 0 << endl;
    return;
  }
  int lowest = a[0];
  int index_change = -1;
  for( int i = 0; i < n; ++ i ) {
    int tmp = a[0] + a[i];
    if( tmp < lowest ) {
      lowest = tmp;
      index_change = i;
    }
  }
  vector<pair<int,int> > operations;

  if( index_change != -1 ) {
    a[0] += a[index_change];
    operations.push_back(make_pair(0,index_change));
  }
  int greatest = a[n-1];
  index_change = -1;
  for( int i = 0; i < n; ++ i ) {
    int tmp = a[n-1] + a[i];
    if( tmp > greatest ) {
      greatest = tmp;
      index_change = i;
    }
  }

  if( index_change != -1 ) {
    a[n-1] += a[index_change];
    operations.push_back(make_pair(0,index_change));
  }
  int index_turn_to_right = 0;
  int index_turn_to_left = n - 1;
  //debug(operations.size());
  //print_vector(a);
  while(true) {
    if( is_non_decreasing(a) )   break;
    int lower_limit = index_turn_to_right == 0 ? -25 : a[index_turn_to_right - 1];
    int current_diff = 50;
    int index_a = 0;
    for( int i = 0; i < n; ++i  ) {
      int tmp = a[index_turn_to_right] + a[i];
      if( tmp >= lower_limit ) {
        int diff = tmp - lower_limit;
        if( diff < current_diff ) {
          current_diff = diff;
          index_a = i;
        }
      }
    }
    //debug(index_turn_to_right,index_a);
    a[index_turn_to_right] += a[index_a];
    operations.push_back(make_pair(index_turn_to_right,index_a));
    if( is_non_decreasing(a) )   break;
    index_turn_to_right = (index_turn_to_right + 1) % n;
    if( operations.size() > 50 ) {
      cout << "Error " << endl;
      print_vector(a,"Error");
      return;
    }

    if( index_turn_to_right >= index_turn_to_left ) break;
    int greater_limit = index_turn_to_left == n-1 ? 25 : a[index_turn_to_left + 1];
    current_diff = 50;
    index_a = 0;
    for( int i = 0; i < n; ++i  ) {
      int tmp = a[index_turn_to_left] + a[i];
      if( tmp <= greater_limit ) {
        int diff = greater_limit - tmp;
        if( diff < current_diff ) {
          current_diff = diff;
          index_a = i;
        }
      }
    }
    //debug(index_turn_to_right,index_a);
    a[index_turn_to_right] += a[index_a];
    operations.push_back(make_pair(index_turn_to_right,index_a));


    index_turn_to_right = (index_turn_to_right + 1) % n;
    if( operations.size() > 50 ) {
      cout << "Error " << endl;
      print_vector(a,"Error");
      return;
    }
    if( index_turn_to_right >= index_turn_to_left ) break;
  }
  //debug(operations.size());
  cout << operations.size() << endl;
  for( int i = 0; i < operations.size(); ++ i ) 
    cout << operations[i].first+1 << " " << operations[i].second+1 << endl;
  
}
