//baekjoon 2251
//물통
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dy[6] = {0, 0, 1, 1, 2, 2};
int dx[6] = {1, 2, 0, 2, 0, 1};
int capacity[3];
int filled[3];
int check[600][600]; //from b and c
int total;

pair<int,int> pour(int y, int x, int dir){
    
    if(capacity[dx[dir]]-x<=y){
        y -= capacity[dx[dir]]-x;
        x = capacity[dx[dir]];
    }
    else if(capacity[dx[dir]]-x>y){
        x += y;
        y = 0;
    }
    return make_pair(y, x);
}


int BFSwater(pair<int,int> &water){
    
	queue<pair<int,int>> list;
	list.push(make_pair(water.first, water.second));
	check[water.first][water.second] = 1;
    while(!list.empty()){
        auto p = list.front();
        int b = p.first;
        int c = p.second;
        filled[0] = total - b - c;
        filled[1] = b;
        filled[2] = c;
        list.pop();
        for(int dir = 0;dir<6;dir++){
            int next[3] = {filled[0], filled[1], filled[2]};
            // auto cur = pour(filled[dy[dir]], filled[dx[dir]], dir);
            next[dx[dir]] += next[dy[dir]];
            next[dy[dir]] = 0;
            if(capacity[dx[dir]]<next[dx[dir]]){
                next[dy[dir]] += next[dx[dir]] - capacity[dx[dir]];
                next[dx[dir]] = capacity[dx[dir]];
            }
            if(check[next[1]][next[2]] == 0){
                check[next[1]][next[2]] = 1;
                list.push(make_pair(next[1], next[2]));
            }
        }
        
    }
	return 0;
}

int main() {
    for(int i = 0;i<3;i++){
        cin>>capacity[i];
        filled[i] = 0;
    }
    total = filled[2] = capacity[2];
    
    pair<int, int> start = make_pair(0, total);
    BFSwater(start);    
    
    vector<int> ans;
    for(int i = 0;i<=total*3;i++){
        for(int j = 0;j<=total*3;j++){
            if(check[i][j] == 1){
                if(i+j == total) ans.push_back(j);
            } 
        }
    }
    sort(ans.begin(), ans.end());
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
	return 0;
}