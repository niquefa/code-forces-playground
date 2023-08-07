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

#define haschar(s,car)   (s.find(car)!=string::npos)

const string codeforces = "codeforces";

int main() {
    int test_cases;
    cin >> test_cases;
    for( int test = 0; test < test_cases; ++ test ) {
      string c;
      cin >> c;
      cout << (haschar(codeforces,c) ? "YES" : "NO") << endl;
    }

    return 0;
}

