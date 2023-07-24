#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");


#define iminel(c)        ((min_element((c).begin(),(c).end()))-(c).begin())
#define minel(c)         (*min_element((c).begin(),(c).end()))
template<class T> map<T,int> get_frecuencies( const vector<T>& v ){map<T,int> ans;for( int i = 0; i < v.size(); ++ i )ans[v[i]]++;return ans;}
template<class T> int find_first( vector< T >& v, T o ){   for( int i = 0; i < v.size(); ++ i )if( v[i] == o )return i; return -1;}

const int MAX = 200001;
int a[MAX];
int f[MAX];
int index_of[MAX];

void solve() {
  int n, tmp;
  cin >> n;
  memset(f, 0, sizeof(f));
  memset(index_of, -1, sizeof(index_of));

  for( int i = 0; i < n; ++ i) {
    cin >> tmp;
    index_of[tmp] = i;
    a[i] = tmp;
    f[tmp]++;
  } 
  
  vector<int> candidates;
  for( int i = 0 ; i < n; ++ i )
    if( f[a[i]] == 1 )
      candidates.push_back(a[i]);

  if( candidates.size() == 0 ) {
    cout << -1 << endl;
    return;
  }

  int minimal = minel(candidates);

  cout << index_of[minimal] + 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  return 0;
}
