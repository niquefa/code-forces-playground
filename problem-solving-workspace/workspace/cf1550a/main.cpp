#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  if( n == 1 ) {
    cout << 1 << endl;
    return;
  }
  if( n <= 4 ) {
    cout << 2 << endl;
    return;
  }
  if( n <= 8 ) {
    cout << 3 << endl;
    return;
  }
  int sum = 1;
  int biggest_so_far = 3;
  int counter = 1;
  while(true){ 
    if( sum + 1 >= n || sum + 2 >= n || sum + biggest_so_far >= n ) {
      counter ++; 
      break;
    }
    sum += biggest_so_far;
    biggest_so_far += 2;
    counter ++;    
  }

  cout << counter << endl;
}

int main() {
  auto start_execution_time = std::chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = std::chrono::high_resolution_clock::now();

  chrono::duration<double, std::milli> elapsed = start_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
