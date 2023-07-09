#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_cases;
	cin >> test_cases;
	for( int test = 0; test < test_cases; ++ test ) {
		int n;
		cin >> n;
		vector<int> a(2*n);
		for( int i = 0; i < 2*n; ++ i) cin >> a[i];
		
		vector<bool> already_printed(n+1,false);
		for( int i = 0; i < 2*n; ++ i) {
			if( !already_printed[a[i]] ) {
				cout << a[i] << " ";
				already_printed[a[i]] = true;
			}
		}
		cout << endl;
	}
	return 0;
}
