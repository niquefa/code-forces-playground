#include <bits/stdc++.h>

using namespace std;

int find_first_char(const std::string& str, char c) {
    auto it = std::find(str.begin(), str.end(), c);
    return it == str.end() ? - 1 : distance(str.begin(), it);
}
int find_last_char(const std::string& str, char c) {
    auto it = std::find_end(str.begin(), str.end(), &c, &c + 1);
    return it == str.end() ? - 1 : distance(str.begin(), it);
}

template<typename T> int find_first_element(const std::vector<T>& v, T element) {
    auto it = std::find(v.begin(), v.end(), element);
    return it == v.end() ? - 1 : distance(v.begin(), it);
}

template<typename T> int find_last_element(const std::vector<T>& v, T element) {
    auto it = std::find_end(v.begin(), v.end(), &element, &element + 1);
    return it == v.end() ? - 1 : distance(v.begin(), it);
}
const string ABCm = "abcdefghijklmnopqrstuvwxyz0123456789";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    string s;
    int n;
    cin >> n >> s;
    int ans = 0;
    for( auto character: s ) {
      int index = find_last_char(ABCm, character);
      ans = max(ans, index);
    }    
    cout << ans + 1 << endl;
  }
  return 0;
}
