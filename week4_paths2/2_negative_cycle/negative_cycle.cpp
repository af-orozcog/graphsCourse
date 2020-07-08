#include <bits/stdc++.h>
using namespace std;
int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
  int use[2][adj.size()];
  for(int i = 0; i < adj.size();++i)
    use[0][i] = use[1][i] = 1000000000;
  use[0][0] = use[1][0] = 0;
  for(int i = 0; i < (int)adj.size()-1;++i){
    for(int j = 0; j < adj.size();++j){
        for(int k = 0; k < adj[j].size();++k){
            use[1][adj[j][k]] = min(use[1][adj[j][k]],use[0][j] + cost[j][k]);
        }
    }
    memcpy(use[0],use[1],sizeof(use[0]));
  }
  int ans = 0;
  for(int j = 0; j < adj.size() && !ans;++j){
        for(int k = 0; k < adj[j].size() && !ans;++k){
            if(use[1][adj[j][k]] > use[0][j] + cost[j][k]) ans = 1;
        }
    }
  return ans;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
