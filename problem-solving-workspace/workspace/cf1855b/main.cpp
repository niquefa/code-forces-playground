#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");


template<class T> void print_vector(const vector<T>& c, const string& vector_name = "") {
  cerr << (!vector_name.empty() ? vector_name : "Vector : ") << "[ ";
  for(auto it = c.begin(); it != c.end(); ++it) {
    if (it != c.begin())
      cerr << " , ";
    cerr << *it;
  }
  cerr << " ] " << c.size() << " Elements." << endl;
}

map<long long, int> factorials_map;
vector<long long> factorials_reverse_order;
void set_factorials() {
  long long factorial = 1;
  for (int i = 1; i <= 20; ++i) {
    factorial *= i;
    factorials_map[factorial] = i;
    if( i > 1 ) 
      factorials_reverse_order.push_back(factorial);
  }
  sort(factorials_reverse_order.begin(), factorials_reverse_order.end(), greater<long long>());
}


vector<long long> get_all_divisors(long long n) {
  vector<long long> divisors;
  divisors.push_back(1); // Remove to not include 1
  for (int i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      if (n / i == i) {
        divisors.push_back(i);
      } else {
        divisors.push_back(i);
        divisors.push_back(n / i);
      }
    }
  }
  sort(divisors.begin(), divisors.end());
  divisors.push_back(n); // Remove to not include n
  return divisors;
}
vector<long long> get_first_divisors(const long long n) {
    vector<long long> divisors;
    for(int i = 1; i <= 1000; i++) {
        if(n % i == 0) {
            divisors.push_back(i);
        }
    }
    return divisors;
}
int brute_force_solution(const long long n){
  vector<long long> divisors = get_all_divisors(n); 
  //get longest consecutive sequence length 
  int ans = 1;
  int current = 1;
  for( int i = 1; i < divisors.size(); ++ i ) {
    if( divisors[i] == divisors[i-1]+1 ) {
      ++ current;
      ans = max(ans,current);
    } else {
      current = 1;
    }
  }
  return ans;
}
int solve(long long);
int main() {
  auto start_execution_time = std::chrono::high_resolution_clock::now();
  // set_factorials();
  // for( int n = 1; n <= 100000; ++ n ) {
  //   int bf = brute_force_solution(n);
  //   int sol = solve(n);
  //   debug(n,bf,sol);
  //   if( bf != sol ) {
  //     debug(n,bf,sol);
  //     exit(0);
  //   }
  // }
  // print_vector(factorials_reverse_order,"factorials_reverse_order");

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    long long n;
    cin >> n;
    //cerr << "\nTest case " << current_test << endl;
    cout << solve(n) << endl;
  }
  auto finish_execution_time = std::chrono::high_resolution_clock::now();

  chrono::duration<double, std::milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
int solve(const long long n) {
  // if( factorials_map.count(n) ) {
  //   return factorials_map[n];
  // }
  if( n%2 != 0 ) {
    return 1;
  }
  // for( int i = 0; i < factorials_reverse_order.size(); ++ i ) {
  //   if( factorials_reverse_order[i] >= n && n%factorials_reverse_order[i] == 0 ) {
  //     return factorials_map[factorials_reverse_order[i]];
  //   }
  // }
  vector<long long> divisors = get_first_divisors(n);
  //debug(n);
  //print_vector(divisors,"divisors");
  int ans = 1;
  int current = 1;
  for( int i = 1; i < divisors.size(); ++ i ) {
    if( divisors[i] == divisors[i-1]+1 ) {
      ++ current;
      ans = max(ans,current);
    } else {
      current = 1;
    }
  }
  return ans;
}
