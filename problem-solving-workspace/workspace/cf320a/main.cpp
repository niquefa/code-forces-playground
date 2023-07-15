#include <bits/stdc++.h>
#include <regex>

using namespace std;

string reduce_string(const string& s) {
    string result = s;
    result = regex_replace(result, regex("144"), "X");
    result = regex_replace(result, regex("14"), "X");
    result = regex_replace(result, regex("1"), "X");
    result = regex_replace(result, regex("X"), "");
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    string cs = reduce_string(s);
    cout << (cs.empty() ? "YES" : "NO") << "\n";
    return 0;
}
