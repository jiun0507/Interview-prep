//baekjoon 17086
//아기상어 2
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dy[12] = {0, 0, 1, -1, -1, -1, 1, 1};
int dx[12] = {1, -1, 0, 0, -1, 1, -1, 1};
int board[210][210];
int n, m;
int dist[210][210];

int BFSmonkey(int r, int c){
	queue<pair<int, int>> list;
	list.push(make_pair(r, c));
	dist[r][c] = 0;
    while(!list.empty()){
        
        int y, x;
        tie(y, x) = list.front();
        list.pop();
        if(board[y][x] == 1) return dist[y][x];
        // cout<<y<<" "<<x<<" "<<jump<<" "<<dist[y][x][jump]<<"\n";
        for(int l = 0; l<8; l++){
            int newy = y + dy[l];
            int newx = x + dx[l];
            if(0 <= newx && newx <m && 0 <= newy && newy < n){
                if(dist[newy][newx] == -1){
                    dist[newy][newx] = dist[y][x] + 1;
                    list.push(make_pair(newy, newx));
                }                      
                
 
            }
        } 

    }
    return -1;
}

int main() {
    cin>>n>>m;;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>board[i][j];
            // cout<<board[i][j]<<" ";
        }
        // cout<<"\n";
    }
    int ans = -1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(board[i][j] == 1) continue;
            memset(dist, -1, sizeof(dist));
            int temp = BFSmonkey(i,j);
            // cout<<i<<" "<<j<<" "<<temp<<"\n";
            if(ans<temp) ans = temp;
        }
    }
    cout<<ans<<"\n";
    // int ans = -1;
    // for(int i =0 ;i<=k;i++){
    //     // cout<<dist[n-1][m-1][i]<<" ";
    //     if(dist[n-1][m-1][i] != -1){
    //         if(ans == -1 || ans > dist[n-1][m-1][i]) ans = dist[n-1][m-1][i];
    //     }
    // }
    
    // cout<<ans<<'\n';
    
    
	return 0;
}