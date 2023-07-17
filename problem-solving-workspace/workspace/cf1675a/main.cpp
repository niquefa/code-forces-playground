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
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    int dog_food, cat_food, universal_food, dogs, cats;
    cin >> dog_food >> cat_food >> universal_food >> dogs >> cats;
    debug( current_test, dog_food, cat_food, universal_food, dogs, cats);
    if( dog_food - dogs >= 0 && cat_food - cats >= 0 ) {
      cout << "YES" << endl;
      continue;
    } else if( dog_food - dogs < 0 && cat_food - cats < 0 ) {
      if( universal_food >= dogs + cats - dog_food - cat_food ) {
        cout << "YES" << endl;
        continue;
      }
    } else if( dog_food - dogs < 0 ) {
      if( universal_food >= dogs - dog_food ) {
        cout << "YES" << endl;
        continue;
      }
    } else if( cat_food - cats < 0 ) {
      if( universal_food >= cats - cat_food ) {
        cout << "YES" << endl;
        continue;
      }
    }
    cout << "NO" << endl;
  }
  return 0;
}
