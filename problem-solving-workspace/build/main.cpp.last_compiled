#include <bits/stdc++.h>
using namespace std;
//Binary Search
void solve();
int main() {
  auto start_execution_time = chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) 
    solve();
  
  auto finish_execution_time = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
template <typename T> int index_max_element(const vector<T>& vec) {
    return vec.empty() ? -1 : distance(vec.begin(), max_element(vec.begin(), vec.end()));
}
int n;
long long k;
bool can_be_done( const vector<long long>& a, int candidate_position, long long candidate_value) {
  long long operations_needed = candidate_value - a[candidate_position];

  candidate_value--;
  for( int j = candidate_position+1; j < n-1; ++ j ) {
    if( a[j] >= candidate_value ) 
      break;
    
    operations_needed += candidate_value - a[j];

    if( operations_needed > k ) 
      return false;
    
    -- candidate_value;
  }

  return operations_needed <= k;
}
void solve() {
  cin >> n >> k;
  vector<long long> a(n);
  for( int i = 0; i < n; ++ i) cin >> a[i];
  
  vector<long long> max_possible_number_in(n);
  vector<long long> operations(n);
  long long ans = a[index_max_element(a)];
  max_possible_number_in[n-1] = a[n-1]; 
  max_possible_number_in[n-2] = a[n-2];

  for( int i = n-2 ; i >= 0 ; --i ) {
    if( max_possible_number_in[i] > max_possible_number_in[i+1]) 
      max_possible_number_in[i] = max_possible_number_in[i];
    else 
      max_possible_number_in[i] = max_possible_number_in[i+1] + 1;
    
    operations[i] = max(0LL,max_possible_number_in[i] - a[i]);
    max_possible_number_in[i] = max(max_possible_number_in[i], a[i]);
  }
  for( int position_to_try_and_set_the_max = 0 ; position_to_try_and_set_the_max < n ; ++ position_to_try_and_set_the_max ) {

    long long low = a[position_to_try_and_set_the_max];
    long long high = max_possible_number_in[position_to_try_and_set_the_max];
    long long mid = (low + high) / 2;

    while( true ) {
      mid = (low + high) / 2;

      if( high - low <= 1 ) {
        for( long long candidate = high; candidate >= low; -- candidate ) 
          if( can_be_done(a, position_to_try_and_set_the_max, candidate) ) 
            ans = max(ans, candidate);
        break;
      }
      
      if( can_be_done(a, position_to_try_and_set_the_max, mid) ) 
        low = mid;
      else 
        high = mid;
    }
  }
  cout << ans << endl;
}
