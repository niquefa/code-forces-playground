#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");
#define vaa(c)           cerr <<#c << " :  "<<endl;for(int II=0;II<(c).size();++II)for(int JJ=0;JJ<(c[II]).size();++JJ)cerr <<(JJ==0?"\t[":"")<<c[II][JJ]<<(JJ==(c[II]).size()-1?"]\n":"|");

void solve();
int main() {
  auto start_execution_time = chrono::high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  auto finish_execution_time = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> elapsed = finish_execution_time - start_execution_time;
  cerr << "\nExecution time: " << elapsed.count() << " milliseconds for " << test_cases << " test cases.\n";
  return 0;
}
bool is_in_cycle(const vector<vector<int>>& adj, int node, int parent, vector<bool>& visited) {
    visited[node] = true;
    
    for(auto v: adj[node]) {
        if(!visited[v]) {
            if(is_in_cycle(adj, v, node, visited))
                return true;
        } else if(v != parent) {
            return true;
        }
    }
    return false;
}

bool is_in_cycle(const vector<vector<int>>& adj, int node) {
    vector<bool> visited(adj.size(), false);
    return is_in_cycle(adj, node, -1, visited);
}

bool possible(const vector<vector<int>>& adj, int a, int b) {
    vector<bool> visited(adj.size(), false);
    vector<int> dist(adj.size(), INT_MAX);

    queue<int> q;
    q.push(a);
    dist[a] = 0;
    visited[a] = true;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(auto v: adj[curr]) {
            if(!visited[v]) {
                visited[v] = true;
                dist[v] = dist[curr] + 1;
                q.push(v);
            }
        }
    }

    for(int i = 1; i <= adj.size() - 1; i++) {
        if(dist[i] < dist[b] && is_in_cycle(adj, i)) {
            return true;
        }
    }

    return false;
}

void solve() {
  int n, a, b, x, y;
  cin >> n >> a >> b;
  vector<vector<int> > adj(n+1, vector<int>()); 
  debug(n,a,b);
  for( int i = 0; i < n; ++ i ) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  if( a == b ) {
    cout << "NO" << endl;
    return;
  }
  if( is_in_cycle(adj,b) ) {
    cout << "YES" << endl;
    return;
  }
  if( possible(adj,a,b) ) {
    cout << "No" << endl;
    return;
  }
  cout << "NO" << endl;
}
