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
void solve() {
  int n,m,d;
  cin >> n>> m >> d;
  debug(n,m,d);
  
  vector<int> s(m + 2);
  for(int i = 1; i <= m; i++) {
      cin >> s[i];
  }
  s[0] = 1-d;
  s[m + 1] = n + 1;
  //print_vector(s);
  int total_spots = 0;
  vector<int> points_up_to(m + 2);
  for( int i = 1; i < points_up_to.size() ; i ++ ) {
    points_up_to[i] = (s[i] - s[i-1]) / d;
    if( (s[i] - s[i-1]) % d == 0 ) points_up_to[i] --;
    //debug(i,points_up_to[i],total_spots);
    total_spots += points_up_to[i];
  }
  total_spots += m;
  //print_vector(points_up_to);
  int max_saved_points = 0;
  for( int i = 1; i <= m ; i ++ ) {
    int points_with_out_i = (s[i+1] - s[i - 1] - 1) / d;
    int points_with_i = 1 + points_up_to[i] + points_up_to[i+1]; 
    //debug(i,points_with_i,points_with_out_i);
    max_saved_points = max(max_saved_points, points_with_i - points_with_out_i);
    //debug(i,max_saved_points);
  }
  debug(total_spots);
  total_spots -= max_saved_points;
  debug(max_saved_points);
  int cnt = 0;
  for( int i = 1; i <= m ; i ++ ) {
    int points_with_out_i = (s[i+1] - s[i - 1] - 1) / d;
    int points_with_i = 1 + points_up_to[i] + points_up_to[i+1]; 
    int saved_points = points_with_i - points_with_out_i;
    if (saved_points == max_saved_points) 
      cnt ++;
    
  }
  cout << total_spots << " " << cnt << endl;
}