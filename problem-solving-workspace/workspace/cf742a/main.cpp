#include <bits/stdc++.h>

using namespace std;

long long fast_mod_pow(long long base, long long exponent, long long mod) {
    base %= mod;
    long long result = 1LL;
    
    while (exponent > 0) {
        if (exponent & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exponent >>= 1;
    }
    return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  cout << fast_mod_pow(1378, n , 10) << endl;
  return 0;
}
