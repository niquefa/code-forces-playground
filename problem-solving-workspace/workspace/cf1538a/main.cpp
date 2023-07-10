#include <bits/stdc++.h>

using namespace std;


template <typename T> int index_max_element(const vector<T>& vec) {
    return vec.empty() ? -1 : distance(vec.begin(), max_element(vec.begin(), vec.end()));
}

template <typename T> int index_min_element(const vector<T>& vec) {
    return vec.empty() ? -1 : distance(vec.begin(), min_element(vec.begin(), vec.end()));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    int n;
    cin >> n;
    vector<int> v(n);
    for( int i = 0; i < n; ++ i) cin >> v[i];
    int index_max = index_max_element(v);
    int index_min = index_min_element(v);

    int a = min(index_max, index_min);
    int b = max(index_max, index_min);
    int option1 = a + 1 + n - b;
    cout << min(option1, min(b+1,n-a)) << endl;

  }
  return 0;
}
