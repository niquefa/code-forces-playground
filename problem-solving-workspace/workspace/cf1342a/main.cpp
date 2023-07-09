#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test_cases;
    cin >> test_cases;
    for( int test = 0; test < test_cases; ++ test ) {
        long long x, y, a , b;
        cin >> x >> y >> a >> b;
        b = min( b , 2 * a );
        if( x < y ) swap( x , y );
        cout << (x - y) * a + y * b << endl;
    }
    return 0;
}
