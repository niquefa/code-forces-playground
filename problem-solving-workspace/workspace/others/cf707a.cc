#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>
#include <sstream>
#include <utility>
#include <cctype>
#include <numeric>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <limits>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <functional>
#include <inttypes.h>
#include <fstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    bool color = false;
    for( int i = 0; !color && i < n; ++i )
      for ( int j = 0; !color && j < m; ++ j ) {
        cin >> s;
        color = s == "C" || s == "M" || s == "Y";
      }
    cout << (color ? "#Color" : "#Black&White") << endl;
    return 0;
}

