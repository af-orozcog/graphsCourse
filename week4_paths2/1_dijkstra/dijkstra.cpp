#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  vector<int> dist(adj.size(),1000000000);
  dist[s] = 0;
  priority_queue<pair<int,int>> q;
  q.push({0,s});
  while(q.size()){
    pair<int,int> see = q.top();
    q.pop();
    if(dist[see.second] > -see.first) continue;
    for(int i = 0; i < adj[see.second].size();++i){
        if(dist[see.second] + cost[see.second][i] < dist[adj[see.second][i]]){
            dist[adj[see.second][i]] = dist[see.second] + cost[see.second][i];
            pair<int,int> append = {-dist[adj[see.second][i]],adj[see.second][i]};
            q.push(append);
        }
    }
  }
  return (dist[t] != 1000000000? dist[t]:-1);
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
