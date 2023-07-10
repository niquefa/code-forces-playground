#include <bits/stdc++.h>

using namespace std;

template<typename T> int find_first_element(const std::vector<T>& v, T element) {
    auto it = std::find(v.begin(), v.end(), element);
    return it == v.end() ? - 1 : distance(v.begin(), it);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<string>a(m);
  vector<string>b(m);
  for( int i = 0; i < m; ++ i)
    cin >> a[i] >> b[i];

  for( int i = 0; i < n; ++ i) {
    string word;
    cin >> word;
    int index_first = find_first_element(a, word);
    if( a[index_first].size() <= b[index_first].size()) {
      cout << word << " ";
    }
    else {
      cout << b[index_first] << " ";
    }
  }
  return 0;
}
