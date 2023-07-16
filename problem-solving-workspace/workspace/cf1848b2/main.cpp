#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
template<class T> map<T,int> get_frecuencies( const vector<T>& v ){map<T,int> ans;for( int i = 0; i < v.size(); ++ i )ans[v[i]]++;return ans;}
#define va(c)            cout<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cout<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"]\n":"|");

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int current_test = 0; current_test < test_cases; ++ current_test ) {
    int n, k;
    cin >> n >> k;
    vector<int> colors(n);
    set<int> different_colors;
    for( int i = 0; i < n; ++ i) {
      cin >> colors[i];
      different_colors.insert(colors[i]);
    } 
    
    if( different_colors.size() <= 1  ) {
      cout << "0" << endl;
      continue;
    }

    if( different_colors.size() == 2  ) {
      map<int,int> frecuencies = get_frecuencies(colors);
      int min_frequency = min(frecuencies.begin()->second, frecuencies.rbegin()->second);
      debug(n,k, min_frequency);
      if( min_frequency == 1 ) {
        cout << "0" << endl;
        continue;
      }
    }
    int answer = -1;
    vector<int> next_not_of_color(n);
    
    for( int i = n-1; i >= 0 ; --i  ) {
      if( i == n-1 ) {
        next_not_of_color[i] = n;
        continue;
      }
      if( colors[i] != colors[i+1] ) {
        next_not_of_color[i] = i+1;
      } else {
        next_not_of_color[i] = next_not_of_color[i+1];
      }
    }

    for( int step_over = 1; ; ++ step_over ) {
      bool can_paint_one_cell = true;
      int color = colors[step_over];
      bool solution_found = true;
      for( int i = step_over; i < n;i += step_over+1) {
        if( colors[i] == color ) {
          int i_before = i;
          i = next_not_of_color[i]-1;
          if( i >= n ) break;
        } else {
          if( !can_paint_one_cell ) {
            solution_found = false;
            break;
          }
          can_paint_one_cell = false;
        }
      }
      if( solution_found ) {
        answer = step_over;
        break;
      }
      can_paint_one_cell = false;
      int real_color_index = step_over + step_over + 1;
      if( real_color_index >= n ) continue;
      color = colors[real_color_index];
      solution_found = true;
      for( int i = 2*step_over + 1; i < n;i += step_over+1) {
        if( colors[i] == color ) {
          int i_before = i;
          i = next_not_of_color[i]-1;
          if( i >= n ) break;
        } else {
          if( !can_paint_one_cell ) {
            solution_found = false;
            break;
          }
          can_paint_one_cell = false;
        }
      }
      if( solution_found ) {
        answer = step_over;
        break;
      }
    }
    cout << answer << endl;
  }
  return 0;
}
