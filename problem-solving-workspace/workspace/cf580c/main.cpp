#include <bits/stdc++.h>

using namespace std;
// BFS, Graphs, Trees
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<bool> has_cat(n,false);
  for( int i = 1; i <= n; ++ i ){
    int x;
    cin >> x;
    has_cat[i] = x == 1;
  }
  vector<int> adj[n+1];
  for( int i = 0; i < n-1; ++ i ){
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  queue<pair<int,int> > q;
  q.push(make_pair(1,has_cat[1]));
  int ans = 0;
  vector<bool> visited(n+1,false);
  while( !q.empty() ){
    pair<int,int> p = q.front();
    q.pop();
    int u = p.first;
    int cats = p.second;

    if( adj[u].size() == 1 && u != 1 ){
      if( cats <= m )
        ans ++;
      continue;
    }
    if( cats > m )
      continue;
    for( int i = 0; i < adj[u].size(); ++ i ){      
      int v = adj[u][i];
      if( v != u ){
        if( visited[v] )
          continue;
        visited[v] = true;
        if( has_cat[v] )
          q.push(make_pair(v,cats+1));
        else
          q.push(make_pair(v,0));
      }
    }
  }
  cout << ans << endl;
  return 0;
}
