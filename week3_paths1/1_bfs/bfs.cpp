#include <iostream>
#include <vector>
#include <queue>
#include<string.h>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  int marked[adj.size()];
  memset(marked,-1,sizeof(marked));
  queue<int> q;
  marked[s] = 0;
  q.push(s);
  while(q.size()){
    int u = q.front();
    q.pop();
    for(auto ad:adj[u]){
        if(marked[ad] == -1){
            marked[ad] = marked[u] + 1;
            q.push(ad);
        }
    }
  }
  return marked[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
