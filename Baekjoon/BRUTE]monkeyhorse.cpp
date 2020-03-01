#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dx[] = {0,0,1,-1,-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,-1,0,0,1,2,2,1,-1,-2,-2,-1};
int cost[] = {0,0,0,0,1,1,1,1,1,1,1,1};
int board[210][210];
int d[210][210][31];

int main() {
    int n, m, l;
    cin>>l;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>board[i][j];
        }
    }
    memset(d, -1, sizeof(d));
    
//     queue<tuple<int, int, int>> list;
// 	list.push(male_tuple(0, 0, 0));
// 	d[0][0][0] = 0;
//     while(!list.empty()){
        
//         int y, x, jump;
//         tie(y, x, jump) = list.front();
//         list.pop();
//         for(int dir = 0; dir<12; dir++){
//             int newy = y + dy[dir];
//             int newx = x + dx[dir];
//             int njump = jump + cost[dir]; 
//             if(0 <= newx && newx < m && 0 <= newy && newy < n){
//                 if(njump<=l){
//                     if(board[newy][newx] == 1) continue;
//                     if(d[newy][newx][njump] == -1){
//                         d[newy][newx][njump] = d[y][x][jump] + 1;
//                         list.push(male_tuple(newy, newx, njump));
//                     }                      
//                 }
 
//             }
//         } 

        
//     }
    memset(d,-1,sizeof(d));
    queue<tuple<int,int,int>> q;
    d[0][0][0] = 0;
    q.push(make_tuple(0,0,0));
    while (!q.empty()) {
        int x, y, c;
        tie(x,y,c) = q.front();
        q.pop();
        for (int l=0; l<12; l++) {
            int nx = x+dx[l];
            int ny = y+dy[l];
            int nc = c+cost[l];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (board[nx][ny] == 1) continue;
                if (nc <= l) {
                    if (d[nx][ny][nc] == -1) {
                        d[nx][ny][nc] = d[x][y][c] + 1;
                        q.push(make_tuple(nx,ny,nc));
                    }
                }
            }
        }
    }
    int ans = -1;
    // cout<<l<<" "<<n<<" "<<m<<"\n";
    // for(int l = 0;l<=l;l++){
    //     for(int i = 0;i<n;i++){
    //         for(int j = 0;j<m;j++){
    //             cout<<d[i][j][l]<<" ";
    //         }
    //         cout<<"\n";
    //     }        
    // }

    for(int i =0 ;i<=l;i++){
        // cout<<d[n-1][m-1][i]<<" ";
        if(d[n-1][m-1][i] == -1) continue;
        if(ans == -1 || ans > d[n-1][m-1][i]) ans = d[n-1][m-1][i];
        
    }
    
    cout<<ans<<'\n';
    
    
	return 0;
}