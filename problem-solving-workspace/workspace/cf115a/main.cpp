#include <bits/stdc++.h>
using namespace std;

template<class T> inline void tmax( T& ans , const T& tmp ){ if( tmp > ans ) ans = tmp;}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a[n+1];
  vector<int> root_nodes;
  for( int i = 1; i <= n; ++ i) {
    int father_of_i;
    cin >> father_of_i;
    if (father_of_i < 0) 
      root_nodes.push_back(i);
    else
      a[father_of_i].push_back(i);
  };
  queue<pair<int,int> > q;
  for( auto root: root_nodes )
    q.push(make_pair(root, 0));

  int max_depth = 0;

  while(!q.empty()) {
    pair<int,int> head = q.front();
    q.pop();
    int node = head.first;
    int depth = head.second;
    tmax(max_depth, depth);
    for( auto child: a[node] )
      q.push(make_pair(child, depth + 1));
    
  }
  cout << max_depth + 1 << endl;
  
  return 0;
}
