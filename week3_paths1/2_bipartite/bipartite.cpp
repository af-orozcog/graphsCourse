#include <iostream>
#include <vector>
#include <queue>
#include<string.h>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  //write your code here
  int marked[adj.size()];
  memset(marked,-1,sizeof(marked));
  queue<int> q;
  marked[0] = 0;
  q.push(0);
  while(q.size()){
    int u = q.front();
    q.pop();
    for(auto ad:adj[u]){
        if(marked[ad] == -1){
            marked[ad] = (marked[u]+1)&1;
            q.push(ad);
        }
        else if(marked[ad] != ((marked[u]+1)&1)) return 0;
    }
  }
  return 1;
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
  std::cout << bipartite(adj);
}
