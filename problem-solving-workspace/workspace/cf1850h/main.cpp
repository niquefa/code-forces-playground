#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cout<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cout<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"]\n":"|");

#define vx(x)            cout<<"{ " << #x << " = "<<x<<" }"<<endl;
#define vx2(x,y)         cout<<"{ " << #x << " = "<<x<<", " << #y << " = "<<y<<" }"<<endl;
#define vx3(x,y,z)       cout<<"{ " << #x << " = "<<x<<", " << #y << " = "<<y<<", " << #z << " = "<<z<<" }"<<endl;
#define vx4(x,y,z,w)     cout<<"{ " << #x << " = "<<x<<", " << #y << " = "<<y<<", " << #z << " = "<<z<<", " << #w << " = "<<w<<" }"<<endl;
#define vx5(x,y,z,w,q)   cout<<"{ " << #x << " = "<<x<<", " << #y << " = "<<y<<", " << #z << " = "<<z<<", " << #w << " = "<<w<<", " << #q << " = "<<q<<" }"<<endl;
#define vx6(x,y,z,w,q,p) cout<<"{ " << #x << " = "<<x<<", " << #y << " = "<<y<<", " << #z << " = "<<z<<", " << #w << " = "<<w<<", " << #q << " = "<<q<<", " << #p << " = "<<p<<" }"<<endl;

const int MAXN = 200005;
vector<pair<int, long long> > neighbors[MAXN];
bool visited[MAXN];
long long position[MAXN];
int node_from[MAXN];
int node_to[MAXN];
long long node_distance[MAXN];

void dfs( const int& node ) {
  visited[node] = true;
  for( auto& neighbor : neighbors[node] ) {
    int next_node = neighbor.first;
    long long distance = neighbor.second;
    if( !visited[next_node] ) {
      position[next_node] = position[node] + distance;
      dfs(next_node);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    int n, m;
    cin >> n >> m;
    for( int i = 1; i <= n ; ++ i ) {
      neighbors[i].clear();
      visited[i] = false;
      position[i] = 0;
    }
    for( int i = 1; i <= m; ++ i) {
      int x , y;
      long long w;
      cin >> x >> y >> w;
      neighbors[x].push_back(make_pair(y, w));
      neighbors[y].push_back(make_pair(x, -w));
      node_from[i-1] = x;
      node_to[i-1] = y;
      node_distance[i-1] = w;
    }

    for( int i = 1; i <= n; ++ i )
      if( !visited[i] )
        dfs(i);

    bool solution_may_exists = true;
    for( int i = 1; solution_may_exists && i <= m; ++ i ) {
      int x = node_from[i-1];
      int y = node_to[i-1];
      long long w = node_distance[i-1];
      if( position[x] + w != position[y] ) {
        cout << "NO\n";
        solution_may_exists = false;
      }
    }
    if( solution_may_exists )
      cout << "YES\n";
  }
  return 0;
}
