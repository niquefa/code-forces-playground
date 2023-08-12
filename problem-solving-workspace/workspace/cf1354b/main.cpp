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


template<class T> map<T,int> get_frequencies( const vector<T>& v ){map<T,int> ans;for( int i = 0; i < v.size(); ++ i )ans[v[i]]++;return ans;}
map<char,int> get_char_frequencies( const string& v ){map<char,int> ans;for( int i = 0; i < v.size(); ++ i )ans[v[i]]++;return ans;}

vector<int> look_to_the_left( const vector<int>& digits, int target ) {
  vector<int> index_to_the_left(digits.size(), -1);
  for( int i = 1; i < digits.size(); ++ i ) 
    index_to_the_left[i] = digits[i-1] == target ? i-1 : index_to_the_left[i-1];
  return index_to_the_left;
}
vector<int> look_to_the_right( const vector<int>& digits, int target ) {
  vector<int> index_to_the_right(digits.size(), -1);
  for( int i = digits.size()-2; i >= 0; --i ) 
    index_to_the_right[i] = digits[i+1] == target ? i+1 : index_to_the_right[i+1];
  return index_to_the_right;
}
void solve() {
  string s;
  cin >> s;
  map<char,int> m = get_char_frequencies(s);
  if( m.size() < 3 ) {
    cout << 0 << endl;
    return;
  }
  
  vector<int> digits;
  transform(s.begin(), s.end(), std::back_inserter(digits), [](char c){return c - '0';});

  vector<int> index_of_1_closest_to_the_left = look_to_the_left(digits, 1);
  vector<int> index_of_1_closest_to_the_right = look_to_the_right(digits, 1);

  vector<int> index_of_2_closest_to_the_left = look_to_the_left(digits, 2);
  vector<int> index_of_2_closest_to_the_right = look_to_the_right(digits, 2);

  vector<int> index_of_3_closest_to_the_left = look_to_the_left(digits, 3);
  vector<int> index_of_3_closest_to_the_right = look_to_the_right(digits, 3);

  // print_vector(index_of_1_closest_to_the_left);
  // print_vector(index_of_1_closest_to_the_right);
  // print_vector(index_of_2_closest_to_the_left);
  // print_vector(index_of_2_closest_to_the_right);
  // print_vector(index_of_3_closest_to_the_left);
  // print_vector(index_of_3_closest_to_the_right);

  int shortest = digits.size();
  for( int i = 0; i < digits.size(); ++i ) {
    
    switch (digits[i])
    {
      case 1:
        if( index_of_2_closest_to_the_left[i] != -1 && index_of_3_closest_to_the_right[i] != -1 )
          shortest = min(shortest, index_of_3_closest_to_the_right[i] - index_of_2_closest_to_the_left[i] + 1);
        if( index_of_3_closest_to_the_left[i] != -1 && index_of_2_closest_to_the_right[i] != -1 )
          shortest = min(shortest, index_of_2_closest_to_the_right[i] - index_of_3_closest_to_the_left[i] + 1);
        break;
      case 2:
        if( index_of_1_closest_to_the_left[i] != -1 && index_of_3_closest_to_the_right[i] != -1 )
          shortest = min(shortest, index_of_3_closest_to_the_right[i] - index_of_1_closest_to_the_left[i] + 1);
        if( index_of_3_closest_to_the_left[i] != -1 && index_of_1_closest_to_the_right[i] != -1 )
          shortest = min(shortest, index_of_1_closest_to_the_right[i] - index_of_3_closest_to_the_left[i] + 1);
        break;
      case 3:
        if( index_of_1_closest_to_the_left[i] != -1 && index_of_2_closest_to_the_right[i] != -1 )
          shortest = min(shortest, index_of_2_closest_to_the_right[i] - index_of_1_closest_to_the_left[i] + 1);
        if( index_of_2_closest_to_the_left[i] != -1 && index_of_1_closest_to_the_right[i] != -1 )
          shortest = min(shortest, index_of_1_closest_to_the_right[i] - index_of_2_closest_to_the_left[i] + 1);
        break;
    }
  }
  cout << shortest << endl;

}

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

  chrono::duration<double, std::milli> elapsed = start_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
