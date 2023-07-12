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
    if( n == 1 ) {
      cout << "1" << endl;
      continue;
    }
    if( n == 2 ) {
      cout << "2 1" << endl;
      continue;
    }
    if( n == 3 ) {
      cout << "3 1 2" << endl;
      continue;
    }
    if( n == 4 ) {
      cout << "2 1 4 3" << endl;
      continue;
    }

    vector<int> solution(n,0);
    int index1;
    if( n % 2 == 1 )
      index1 = n/2;
    else
      index1 = n/2-1;
    solution[index1] = 1;
    solution[0] = 2;
    solution[n-1] = 3;

    int next_number = 4;
    for( int i = 0;i < n; ++ i )
      if( solution[i] == 0 )
        solution[i] = next_number++;
    for( int i = 0; i < n; ++ i ) 
      cout << solution[i] << " ";
    cout << endl;
  }
  return 0;
}
