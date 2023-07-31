#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


template<class K, class V> set<K> key_set(const map<K, V>& m) {
    set<K> keys;
    for (const auto& pair : m) 
        keys.insert(pair.first);
    return keys;
}

void solve();

map<long long, int> squares;
set<long long> squares_set;
int main() {
  auto start_execution_time = chrono::high_resolution_clock::now();
  for( long long i = 1; i*i <= 10000000000; ++ i ) squares[i*i] = (int)i;
  //debug(squares.size());
  squares_set = key_set(squares);
  //print_set(squares_set);
  vector<long long> squares_vector(squares_set.begin(), squares_set.end());
  set<long long> differences;
  for( int i = 1; i < squares_vector.size(); ++ i ) 
    differences.insert(squares_vector[i] - squares_vector[i-1]);
  //print_set(differences);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    //cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}

void solve() {
  long long k;
  cin >> k;
  if( k == 1 ) {
    cout << "1 1" << endl;
    return;
  }
  if( squares.count(k) ) {
    cout << squares[k] << " " << 1 << endl;
    return;
  }
  long long perfect_square = *squares_set.lower_bound(k);
  
  long long number = perfect_square;
  long long col = 1;
  long long row = squares[perfect_square];
  long long perfect_square_limit = row;
  //debug(k, perfect_square, col, row, perfect_square_limit);
  for( int i = 0; i < perfect_square_limit; ++ i ) {
    //debug(i,number,k,row,col);
    if( number == k ) {
      cout << row << " " << col << endl;
      return;
    }
    --number;
    ++col;
  }
  --row;
  while(true){
    //debug(number,k,row,squares[perfect_square]);
    if( number == k ) {
      cout << row << " " << squares[perfect_square] << endl;
      return;
    }
    --number;
    --row;
  }
  cout << "UNKNOWN" << endl;
}
