#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>
#include <sstream>
#include <utility>
#include <cctype>
#include <numeric>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <limits>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <functional>
#include <inttypes.h>
#include <fstream>
using namespace std;

const int MAX = 2147483600;
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
  int s = 0;    //starting node
  int t = n-1;  //end node
  vector<edge> g[n];
  int u, v;
  long long w;
  //map<pair<int, int>, int> edges;
  while(m--) {
    cin >> u >> v >> w;
    if (u == v) continue;
    u--; v--;
    g[u].push_back(edge(v, w));
    g[v].push_back(edge(u, w));
  }

  for( int i = 0; i < n; ++i ) {
    cout << "Node i" << i << ": ";
    for( int j = 0; j < g[i].size(); ++j ) {
      cout << g[i][j].to << " ("<<g[i][j].weight<<") ";
    }
    cout << endl;
  }

  // long long d[n];
  // for (int i = 0; i < n; ++i)
  //   d[i] = MAX;
  // d[s] = 0;

  // int parent[n];
  // parent[s] = -1;

  // priority_queue<edge> q;
  // q.push(edge(s, 0));

  // while (q.empty() == false){
  //   int node = q.top().to;
  //   long long dist = q.top().weight;
  //   q.pop();
  //   if (dist > d[node]) continue;
  //   if (node == t) break;
  //   for (int i = 0; i < g[node].size(); ++i){
  //     int to = g[node][i].to;
  //     long long w_extra = g[node][i].weight;
  //     if (dist + w_extra < d[to]){
  //       d[to] = dist + w_extra;
  //       q.push(edge(to, d[to]));
  //       parent[to] = node;
  //     }
  //   }
  // }
  // for( int i = 0; i < n ; ++i ) {
  //   cout << d[i] << " ";
  // }
  // cout << endl;
  // for( int i = 0; i < n ; ++i ) {
  //   cout << parent[i] << " ";
  // }
  // cout << endl;
  
  // if( d[t] == MAX ) {
  //   cout << -1 << endl;
  //   return 0;
  // }
  // vector<int> path(1, t);
  // int current_node = t;
  // while(true) {
  //   int p = parent[current_node];
  //   if (p == -1) break;
  //   current_node = p;
  //   path.push_back(p);
  // }
  // for( int i = path.size()-1; i >= 0; -- i )
  //   printf("%d ", path[i]+1);
  // cout << endl;
  return 0;
}