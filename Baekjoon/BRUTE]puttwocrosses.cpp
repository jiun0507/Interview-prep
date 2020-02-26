//baekjoon 17085
//십자가 2개 놓기
#include <iostream>
#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;
int n,m;
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

bool check_range(int y, int x, vector<vector<int>> &board){
    return y>=0 && y<n && x>=0 && x<m && board[y][x] == 0;
}

int go(int put, vector<vector<int>> &board){
    if(put == 2){
        return 1;
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            int y = i;
            int x = j;
            if(!check_range(y, x, board)) continue;
            int length = 0;
            for(length = 0;length<=n/2;length++){
                int right = x+dx[0]*length;
                int left =  x+dx[1]*length;
                int up = y+dy[2]*length;
                int down = y+dy[3]*length;
                if(check_range(up, x, board) && check_range(down,x, board) && check_range(y,left, board) && check_range(y,right, board)){
                    board[up][x] = 1;
                    board[down][x] = 1;
                    board[y][right] = 1;
                    board[y][left] = 1;
                    int temp = (1+4*length) * go(put+1, board);
                    if(ans<temp) ans = temp;
                    // cout<<y<<" "<<x<<" "<<length<<"\n";
                }
                else{
                    break;
                }
            }
            if(length == 0){
                board[y][x] = 0;
                continue;
            }
            length--;
            // cout<<length<<"\n";
            while(length > 0){
                int right = x+dx[0]*length;
                int left =  x+dx[1]*length;
                int up = y+dy[2]*length;
                int down = y+dy[3]*length;
                board[up][x] = 0;
                board[down][x] = 0;
                board[y][right] = 0;
                board[y][left] = 0;
                length-=1;
            }
            board[y][x] = 0;
        }
    }
    return ans;
}


int main(void){
    cin>>n>>m;
    vector<vector<int>> board(n, vector<int>(m));
    for(int i = 0;i<n;i++){
        string str;
        cin>>str;
        for(int j = 0;j<m;j++){
            if(str.at(j) == '#') board[i][j] = 0;
            else{
                board[i][j] = 1;
            }
        }
    }

    
    int ans = go(0, board);
    cout<<ans<<"\n";
    
}