#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


template<typename T> void print_set( const set<T>& s ) {
  cout << "{";
  for( auto it = s.begin(); it != s.end(); ++ it ) {
    if( it != s.begin() )
      cout << ", ";
    cout << *it;
  }
  cout << "}" << endl;
}



const int MAX = 200001;
int father_of[MAX];
bool leafs[MAX];
long long leafs_accessible_from_cache[MAX];
bool visited[MAX];

vector < vector<int> > adj(MAX, vector<int> ());
int n;

long long get_leafs_accessible_from( const int& node ) {
  
  if( leafs[node] )
    return 1;
  
  if( leafs_accessible_from_cache[node] != -1 )
    return leafs_accessible_from_cache[node];

  long long ans = 0;
  for( int i = 0; i < adj[node].size(); ++ i )
    if( adj[node][i] != father_of[node])
      ans += get_leafs_accessible_from(adj[node][i]);
  
  leafs_accessible_from_cache[node] = ans;
  return ans;
}

void fill_sets() {
  queue<int> q;
  q.push(1);
  memset(visited, false, sizeof visited);
  visited[1] = true;
  while( !q.empty() ) {
    int node = q.front();
    visited[node] = true;
    q.pop();
    for( int i = 0; i < adj[node].size(); ++ i ) {
      int son = adj[node][i];
      if( visited[son] )continue;
      father_of[son] = node;
      q.push(son);
    }
  }
  for( int i = 1; i <= n; ++ i )
    if( father_of[i] != -1 && adj[i].size() == 1 )
      leafs[i] = true;
}
// graph problems bfs dp memoization dynamic programming
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cin >> n;
    memset(leafs, false, sizeof leafs); 
    memset(leafs_accessible_from_cache, -1, sizeof leafs_accessible_from_cache);
    memset(father_of, -1, sizeof father_of);
    set<int> fathers;
    for( int i = 0; i <= n; ++ i)
      adj[i].clear();

    for( int i = 0; i < n - 1; ++ i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    fill_sets();
    int q;
    cin >> q;
    for( int i = 0; i < q; ++ i) {
      int x, y;
      cin >> x >> y;
      long long leafs_accessible_from_x = get_leafs_accessible_from(x);
      long long leafs_accessible_from_y = get_leafs_accessible_from(y);
      cout << leafs_accessible_from_x * leafs_accessible_from_y << endl;
    }
    
  }
  return 0;
}
