#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) {
  //write your code here
  used[x] = 1;
  for(auto ad:adj[x]){
    if(!used[ad])
        dfs(adj,used,order,ad);
  }
  order.push_back(x);
}


int number_of_strongly_connected_components(vector<vector<int> > adj) {
  vector<int> used(adj.size(), 0);
  vector<int> order;
  vector<vector<int>> reverseGraph(adj.size());
  for(int i = 0; i < adj.size();++i){
    for(auto ad:adj[i]){
        reverseGraph[ad].push_back(i);
    }
  }
  //write your code here
  for(int i = 0; i < adj.size();++i){
    if(!used[i])
        dfs(reverseGraph,used,order,i);
  }
  reverse(order.begin(),order.end());
  vector<int> seen(adj.size(),0);
  int result = 0;
  for(int i = 0; i < order.size();++i){
    if(!seen[order[i]]){
        ++result;
        dfs(adj,seen,order,order[i]);
    }
  }
  //write your code here
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
