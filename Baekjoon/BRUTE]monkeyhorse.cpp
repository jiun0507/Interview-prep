//baekjoon 1600
//말이 되고픈 원숭이
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dy[12] = {0, 0, 1, -1,-2, -2,-1, -1, 1, 1, 2, 2};
int dx[12] = {1, -1, 0, 0, -1, 1, -2, 2, -2, 2, -1, 1};
int cost[12] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};
int board[210][210];
int n, m, k;
int dist[210][210][31];

void BFSmonkey(){
	queue<tuple<int, int, int>> list;
	list.push(make_tuple(0, 0, 0));
	dist[0][0][0] = 0;
    while(!list.empty()){
        
        int y, x, jump;
        tie(y, x, jump) = list.front();
        list.pop();
        // cout<<y<<" "<<x<<" "<<jump<<" "<<dist[y][x][jump]<<"\n";
        for(int l = 0; l<12; l++){
            int newy = y + dy[l];
            int newx = x + dx[l];
            int njump = jump + cost[l]; 
            if(0 <= newx && newx <m && 0 <= newy && newy < n){
                if(njump<=k){
                    if(board[newy][newx] == 1) continue;
                    if(dist[newy][newx][njump] == -1){
                        dist[newy][newx][njump] = dist[y][x][jump] + 1;
                        list.push(make_tuple(newy, newx, njump));
                    }                      
                }
 
            }
        } 

        
    }
}

int main() {
    cin>>k;
    cin>>m>>n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>board[i][j];
            // cout<<board[i][j]<<" ";
        }
        // cout<<"\n";
    }
    memset(dist, -1, sizeof(dist));
    BFSmonkey();
    int ans = -1;
    for(int i =0 ;i<=k;i++){
        // cout<<dist[n-1][m-1][i]<<" ";
        if(dist[n-1][m-1][i] != -1){
            if(ans == -1 || ans > dist[n-1][m-1][i]) ans = dist[n-1][m-1][i];
        }
    }
    
    cout<<ans<<'\n';
    
    
	return 0;
}