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
    int n;
    cin >> n;
    int s = 0;
    int ans = 0;
    int c = 1;
    int blocks = 0;
    while(true) {
      s += c;
      blocks += s;
      if(blocks > n) break;
      ans++;
      c++;
      if(blocks == n)break;
    }
    cout << ans << endl;
    return 0;
}

