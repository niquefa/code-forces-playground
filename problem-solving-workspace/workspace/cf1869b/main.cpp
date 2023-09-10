#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");
void solve();
int main() {
  auto start_execution_time = chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) solve();
  auto finish_execution_time = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
const long long INF = 1LL<<40;


long long get_dist( int i, int j , const vector<int> &x , const vector<int> &y) {
  return (long long)abs(x[i] - x[j]) + (long long)abs(y[i] - y[j]);
}


void solve() {
  int n, k, a, b;
  cin >> n >> k >> a >> b;

  vector<int> x(n), y(n);
  for(int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  
  --a; --b;
  if(a < k && b < k) {
    cout << 0 << '\n';
    return;
  }

  vector<long long> dist_to_super_node(n, INF);

  for(int i = 0; i < k; ++i) {
    for(int j = k; j < n; ++j) {
      dist_to_super_node[j] = min(dist_to_super_node[j], get_dist(i, j, x, y));
    }
  }

  if(a < k || b < k) {
    int outside_super_node = (a < k) ? b : a;
    cout << dist_to_super_node[outside_super_node] << '\n';
    return;
  }

  vector<vector<pair<int, long long>>> adj(n);
  for(int i = k; i < n; ++i) {
    for(int j = i+1; j < n; ++j) {
      long long dist = get_dist(i, j, x, y);
      adj[i].emplace_back(j, dist);
      adj[j].emplace_back(i, dist);
    }
  }

  auto dijkstra = [&](int src) {
    vector<long long> dist(n, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[src] = 0;
    pq.emplace(0, src);
    while(!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      if(d > dist[u]) continue;
      for(auto [v, w] : adj[u]) {
        if(dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          pq.emplace(dist[v], v);
        }
      }
      if(u >= k && k > 0) {
        long long dist_to_supernode = dist[u] + dist_to_super_node[u];
        if(dist_to_supernode < dist[k-1]) {
          dist[k-1] = dist_to_supernode;
          pq.emplace(dist[k-1], k-1);
        }
      }
    }
    return dist;
  };

  vector<long long> dist_from_a = dijkstra(a);
  vector<long long> dist_from_b = dijkstra(b);

  long long min_dist = dist_from_a[b];
  for(int i = 0; i < n; ++i) {
    if(i != a && i != b) {
      min_dist = min(min_dist, dist_from_a[i] + dist_from_b[i]);
    }
  }

  cout << min_dist << '\n';
}
