#include<bits/stdc++.h>
#define ll long long

using namespace std;

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  //write your code here
  ll temp[adj.size()];
  for(int i = 0; i < adj.size();++i)
    temp[i] = distance[i];
  temp[s] = distance[s] = 0;
  reachable[s] = 1;
  for(int i = 0;i < (int)adj.size()-1;++i){
    for(int j = 0; j < adj.size();++j){
        if(temp[j] == numeric_limits<long long>::max()) continue;
        for(int k = 0; k < adj[j].size();++k){
            temp[adj[j][k]] = min(temp[adj[j][k]],temp[j]+(ll)cost[j][k]);
            if(temp[adj[j][k]] != numeric_limits<long long>::max())
                reachable[adj[j][k]] = 1;
        }
        for(int i = 0; i < adj.size();++i)
            distance[i] = temp[i];
    }
  }
  queue<int> q;
  for(int j = 0; j < adj.size();++j){
        if(temp[j] == numeric_limits<long long>::max()) continue;
        for(int k = 0; k < adj[j].size();++k)
            if(temp[j]+cost[j][k] < temp[adj[j][k]]) q.push(adj[j][k]);
  }
  vector<int> visited(adj.size(),0);
  while(q.size()){
    int f = q.front();
    q.pop();
    shortest[f] = 0;
    for(auto va:adj[f]){
        if(!visited[va]){
            q.push(va);
            visited[va] = 1;
        }
    }
  }
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
