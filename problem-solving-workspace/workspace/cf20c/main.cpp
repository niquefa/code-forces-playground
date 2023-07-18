#include <bits/stdc++.h>
 
using namespace std;
const long long MAX = 1ll<<60;
 
struct edge{
  int to;
  long long weight;
  edge() {}
  edge(int t, long long w) : to(t), weight(w) {}
  bool operator < (const edge &that) const {
    return weight > that.weight;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
 
  int n, m;
  cin >> n >> m;
  int s = 1;  //starting node
  int t = n;  //end node
 
  vector<edge> g[n+1];
  int u, v;
  long long w;
 
  while(m--) {
    cin >> u >> v >> w;
    if( u == v ) continue;
 
    g[u].push_back(edge(v, w));
    g[v].push_back(edge(u, w));
  }
 
  long long d[n+1];
  int parent[n+1];
  vector<bool> processed(n+1, false);  // Adding processed array
 
  for (int i=0; i<=n; ++i) {
    d[i] = MAX;
    parent[i] = -1;
  }
 
  d[s] = 0LL;
  priority_queue<edge> q;
  q.push(edge(s, 0LL));
 
  while (q.empty() == false){
    int node = q.top().to;
    long long dist = q.top().weight;
    q.pop();
 
    for (int i=0; i < g[node].size(); ++i){
      int to = g[node][i].to;
      long long w_extra = g[node][i].weight;
 
      if (d[to] > d[node] + w_extra ){
        d[to] = d[node] + w_extra ;
        parent[to] = node;
        q.push(edge(to, d[to]));
      }
    }
  }
 
  if (d[n] == MAX) {
      cout << -1;
      return 0;
  }
  vector<int> path;
  for (int v = n; v != 1; v = parent[v])
      path.push_back(v);
  path.push_back(1);
  reverse(path.begin(), path.end());
  for (int v : path)
      cout << v << ' ';
  return 0;
}