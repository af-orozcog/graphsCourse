#include <bits/stdc++.h>

using namespace std;

int dad[300];

int search(int x){
    return dad[x] == x? x: (dad[x] = search(dad[x]));
}

bool connected(int x, int y){
    return search(x) == search(y);
}

void UF(int x, int y){
    int dadX = search(x),dadY = search(y);
    if(dadX != dadY){
        dad[dadX] = dadY;
    }
}

double minimum_distance(vector<int> x, vector<int> y) {
    double result = 0.;
    //write your code here
    priority_queue<pair<double,pair<int,int>>> q;
    for(int i = 0; i < x.size();++i){
        dad[i] = i;
        for(int j = i+1; j < x.size();++j){
            double dist = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
            q.push({-dist,{i,j}});
        }
    }
    while(q.size()){
        pair<double,pair<int,int>> see = q.top();
        q.pop();
        if(!connected(see.second.first,see.second.second)){
            UF(see.second.first,see.second.second);
            result += -see.first;
        }
    }
    return result;
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> x(n), y(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
