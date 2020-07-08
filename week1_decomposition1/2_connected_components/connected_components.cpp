#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void dfs(int node, vector<vector<int>> &graph,vector<int> &marked){
    marked[node] = 1;
    for(auto adjacent:graph[node]){
        if(!marked[adjacent])
            dfs(adjacent,graph,marked);
    }
}

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  vector<int> marked(adj.size(),0);
  for(int i = 0; i < adj.size();++i){
    if(!marked[i]){
        dfs(i,adj,marked);
        ++res;
    }
  }
  //write your code here
  return res;
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
  std::cout << number_of_components(adj);
}
