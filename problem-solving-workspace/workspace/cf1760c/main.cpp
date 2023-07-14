#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n;
    cin >> n;
    vector<int> a(n);
    for( int i = 0, tmp; i < n; ++ i){ 
      cin >> tmp;
      a[i] = tmp;
    }
    multiset<int> s(a.begin(), a.end());
    for( auto element : a ){
      auto it = s.find(element);
      s.erase(it);

      auto biggest_without_current_element = s.end();
      --biggest_without_current_element;

      cout << element - *biggest_without_current_element << " ";

      s.insert(element);
    }
    cout << endl;
  }
  return 0;
}
