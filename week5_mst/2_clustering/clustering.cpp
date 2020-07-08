#include <bits/stdc++.h>
using namespace std;

int UF[300];

int search(int x){
    return (UF[x] == x ? x: (UF[x] = search(UF[x])));
}

bool connected(int x, int y){
    return search(x) == search(y);
}

void connect(int x, int y){
    int dadX = search(x), dadY = search(y);
    if(dadX != dadY)
        UF[dadX] = dadY;
}

double clustering(vector<int> x, vector<int> y, int k) {
  //write your code here
  for(int i = 0; i < x.size();++i)
    UF[i] = i;
  int components = x.size();
  priority_queue<pair<double,pair<int,int>>> q;
  for(int i = 0; i < x.size();++i){
    for(int j = i+1; j < x.size();++j){
        double dist = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
        q.push({-dist,{i,j}});
    }
  }
  while(q.size() && components > k){
    pair<double,pair<int,int>> see = q.top();
    q.pop();
    if(!connected(see.second.first,see.second.second)){
        --components;
        connect(see.second.first,see.second.second);
    }
  }
  double ans = -1.0;
  while(ans == -1.0){
    pair<double,pair<int,int>> see = q.top();
    q.pop();
    if(!connected(see.second.first,see.second.second)){
        ans = -see.first;
    }
  }
  return ans;
}

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
}
