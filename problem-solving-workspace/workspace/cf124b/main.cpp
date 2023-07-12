#include <bits/stdc++.h>
using namespace std;

int f( const string& s, const vector<int>& p ) {
  int n = s.size();
  vector<char> new_s(n);
  for( int i = 0; i < n; ++ i ) new_s[i] = s[p[i]];

  string str(new_s.begin(), new_s.end());

  return std::stoi(str);
}

template<class T> inline void tmax( T& ans , const T& tmp ){ if( tmp > ans ) ans = tmp;}
template<class T> inline void tmin( T& ans , const T& tmp ){ if( tmp < ans ) ans = tmp;}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<string> v(n);
  vector<int> p(k);
  for (int i = 0; i < n; ++i)
    cin >> v[i];
  for (int i = 0; i < k; ++i)
    p[i] = i;
  
  int best_difference = 999999999, max_number, min_number;
  do {
    max_number = f(v[0],p);
    min_number = max_number;

    for( int i = 1; i < n; ++ i ) {
      int number = f(v[i],p);
      tmax(max_number, number);
      tmin(min_number, number);
    }

    best_difference = min(best_difference, max_number - min_number);
  } while (next_permutation(p.begin(), p.end()));
  cout << best_difference << endl;
  return 0;
}
