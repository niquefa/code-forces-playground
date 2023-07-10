#include <bits/stdc++.h>

using namespace std;

int find_first_char(const std::string& str, char c) {
    auto it = std::find(str.begin(), str.end(), c);
    return it == str.end() ? - 1 : distance(str.begin(), it);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for( int test = 0; test < test_cases; ++ test ) {
    string alphabet, word;
    cin >> alphabet >> word;
    int ans = 0;
    for( int i = 1; i < word.size(); ++ i ) {
      int index = find_first_char(alphabet, word[i]);
      int index_previus = find_first_char(alphabet, word[i-1]);
      ans += abs(index - index_previus);
    }

    cout << ans << endl;
  }
  return 0;
}
