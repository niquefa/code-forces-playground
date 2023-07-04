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
    int test_cases, n, k;
    cin >> test_cases;
    for( int test = 0; test < test_cases; ++ test ) {
      cin >> n >> k;      
      cout << k + ((k - 1) / (n - 1)) << endl;
    }
    return 0;
}

