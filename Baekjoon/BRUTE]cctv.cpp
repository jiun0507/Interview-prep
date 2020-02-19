//baekjoon 15683
//감시
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
vector<pair<int,int>> cameras;

void watch(vector<vector<int>> &curboard, int y, int x, int direc){
     int type = curboard[y][x];
     int up, down, left, right;
     up = down = left = right = 0;
     if(type == 1){
         if(direc == 0) right = -1;
         else if(direc == 1) down = -1;
         else if(direc == 2) left = -1;
         else if(direc == 3) up =-1;
     }
     else if(type == 2){
         if(direc == 0 || direc == 2){
             right = left =-1;
         }
         else{
             up = down =-1;
         }
     }
     else if(type == 3){
         if(direc == 0) right = down =-1;
         else if(direc == 1) down = left = -1;
         else if(direc == 2) left = up = -1;
         else if(direc == 3) up = right = -1;
     }
    else if(type == 4){
        up = down =right = left =-1;
        if(direc == 0) left = 0;
        else if(direc == 1) up = 0;
        else if(direc == 2) right = 0;
        else if(direc == 3) down = 0;
     }
    else if(type == 5){
        up = down =right = left =-1;
    }
    for(int i = y-1;i>=0;i--){
        if(curboard[i][x]==6) break;
        if(curboard[i][x] == 0) curboard[i][x] = up;
    }
    for(int i = y+1;i<n;i++){
        if(curboard[i][x]==6 )break;
        if(curboard[i][x] == 0) curboard[i][x] = down;
    }
    for(int j = x-1;j>=0;j--){
        if(curboard[y][j]==6)break;
        if(curboard[y][j] == 0) curboard[y][j] = left;
    }
    for(int j = x+1;j<m;j++){
        if(curboard[y][j]==6)break;
        if(curboard[y][j] == 0) curboard[y][j] = right;
    }
    return;
}

vector<int> makevector(int bit, int size){
    vector<int> directions;
    for(int i = 0;i<size;i++){
        directions.push_back(bit&3);
        bit >>=2;
    }
    return directions;
}

int go(vector<vector<int>> &board, vector<int> &directions){
    
    for(int i = 0;i<directions.size();i++){
        int y,x;
        y = cameras[i].first;
        x = cameras[i].second;
        watch(board, y, x, directions[i]);
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(board[i][j] == 0) ans++;
            
        }
    }
    return ans;
}

int main(void){
    cin>>n>>m;
    vector<vector<int>> board(n, vector<int>(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>board[i][j];
            if(board[i][j] > 0 && board[i][j] <= 5){
                cameras.push_back(make_pair(i,j));
            }
        }
    }
    int ans = -1;
    
    for(int i = 0;i<(1<<(2*cameras.size()));i++){
        vector<int> directions = makevector(i, cameras.size());
        vector<vector<int>> curboard(board);
        int partial = go(curboard, directions);
        if(ans == -1 || partial <ans){
            ans = partial;
        }
        
    }
    
    cout<<ans<<"\n";
}