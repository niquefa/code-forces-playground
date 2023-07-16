#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int current_test = 0; current_test < test_cases; ++ current_test ) {
    int n, k;
    cin >> n >> k;
    vector<int> colors(n+2);
    set<int> different_colors;
    for( int i = 1; i <= n; ++ i) {
      cin >> colors[i];
      different_colors.insert(colors[i]);
    } 
    
    if( different_colors.size() <= 1  ) {
      cout << "0" << endl;
      continue;
    }
    //cout << "\n\nCase " << current_test + 1 << ": ";
    int answer = 999999999;
    for (const int& c : different_colors) {
      //cout << "Color " << c << endl;
      int biggest_sequence_with_no_color_c = 0, second_biggest_sequence_with_no_color_c = 0;
      int current_count = 0;
      colors[0] = colors[colors.size()-1] = c;
      for( int i = 0; i < colors.size(); ++ i ) {
        if( colors[i] == c ) {
          if( current_count > biggest_sequence_with_no_color_c ) {
            second_biggest_sequence_with_no_color_c = biggest_sequence_with_no_color_c;
            biggest_sequence_with_no_color_c = current_count;
          } else if( current_count > second_biggest_sequence_with_no_color_c ) {
            second_biggest_sequence_with_no_color_c = current_count;
          }
          current_count = 0;
          continue;
        }
        ++ current_count;
      }
      //cout << "biggest_sequence_with_no_color_c " << biggest_sequence_with_no_color_c << endl;
      //cout << "second_biggest_sequence_with_no_color_c " << second_biggest_sequence_with_no_color_c << endl;
      //debug(biggest_sequence_with_no_color_c);
      //debug(second_biggest_sequence_with_no_color_c);
      int biggest_splitted = biggest_sequence_with_no_color_c / 2;
      //debug(biggest_splitted);
      //cout << "biggest_splitted " << biggest_splitted << endl;
      answer = min(answer, max(biggest_splitted, second_biggest_sequence_with_no_color_c));
    }
    //debug(current_test + 1 , answer ) ;
    cout << answer << endl;
  }
  return 0;
}
