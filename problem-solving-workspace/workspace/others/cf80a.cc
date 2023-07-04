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

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 
  61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 
  151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 
  241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 
  349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 
  449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n ,m;
  cin >> n >> m;
  int next_prime = -1;
  for( int i = 0; ; ++i ) {
    if( primes[i] == n ) {
      next_prime = primes[i+1];
      break;
    }
    if( primes[i] > n ) {
      next_prime = primes[i];
      break;
    }
  }
  cout << ( next_prime == m ? "YES" : "NO") << endl;
  return 0;
}

