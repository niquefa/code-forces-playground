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
    vector<int> solution(n,0);
    if( n % 2 == 1 )
      solution[n/2] = 1;
    else
      solution[n/2-1] = 1;
    vector<int> firstones;
    vector<int> secondones;
    for( int i = 1; 1 <= n; ++ i )
      if( isPrime(i+1))
        firstones.push_back(i+1);
      else:
        secondones.push_back(i+1);
    

    for( int i = 0, j = 0; i < n && j < firstones.size(); ++ i ) {
      if( solution[i] != 0 )
        continue;
      solution[i] = firstones[j];
    }

    for( int i = 0; i < n; ++ i ) 
      cout << solution[i] << " ";
    cout << endl;
  }
  return 0;
}
