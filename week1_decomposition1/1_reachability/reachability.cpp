#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void dfs(int node,vector<vector<int>> &graph,vector<int> &marked, int color){
    marked[node] = color;
    for(auto neigh: graph[node]){
        if(marked[neigh] == -1)
            dfs(neigh,graph,marked,color);
    }
}


int reach(vector<vector<int> > &adj, int x, int y) {
  vector<int> marked((int)adj.size(),-1);
  for(int i = 0, j = 0; i < (int)adj.size();++i){
    if(marked[i] == -1){
        dfs(i,adj,marked,j++);
    }
  }
  return marked[x] == marked[y];
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
