#include <iostream>
#include <vector>

using std::vector;
using std::pair;
bool dfs(int p, vector<vector<int>> &graph, vector<int> &seen, vector<int> &sta){
    bool ans = 1;
    seen[p] = 1;
    sta[p] = 1;
    for(auto adj:graph[p]){
        if(seen[adj] != 0 && sta[adj]) ans = ans & false;
        else if(!seen[adj])
            ans = ans & dfs(adj,graph,seen,sta);
    }
    sta[p] = 0;
    return ans;
}

int acyclic(vector<vector<int> > &adj) {
  vector<int> seen(adj.size(),0);
  vector<int> stac(adj.size(),0);
  int ans = 0;
  for(int i = 0; i < adj.size();++i){
    if(!seen[i]){
        ans = ans | !dfs(i,adj,seen,stac);
    }
  }
  return ans;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
