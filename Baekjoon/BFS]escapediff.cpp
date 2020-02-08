//3055
//탈출
#include <iostream>
#include <vector>
#include <queue>
#include <tuple> 
#include <string>
#include <algorithm>
using namespace std;

int n,m;
int check[50][50][150];
vector<vector<int>> blocks[150];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int cnt;
int cavey,cavex;
bool check_range(int y, int x){
    return y>=0 && y<n && x>=0 && x<m;
}


bool water(vector<vector<int>> &turns){
    bool moved = false;
    vector<pair<int,int>> waters;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(turns[i][j] == -1){
                waters.push_back(make_pair(i,j));
            }
        }
    }
    for(auto p: waters){
        int i = p.first;
        int j = p.second;
        for(int k = 0;k<4;k++){
            int ni = i + dy[k];
            int nj = j + dx[k];
            if(!check_range(ni, nj)) continue;
            if(turns[ni][nj] == -1|| turns[ni][nj] == 1 ||turns[ni][nj] == 3) continue;
            moved = true;
            turns[ni][nj] = -1;
        }
    }
    return moved;
}


bool go(int a, int b, int turn){
    queue<tuple<int, int,int>> q;
    q.push(make_tuple(a, b,turn));
    check[a][b][turn] = 1;
    while(!q.empty()){
        int y, x, z;
        tie(y, x, z) = q.front();
        q.pop();
        if(y== cavey && x == cavex) return true;
        if(z > cnt) return false;
        for(int i = 0;i<4;i++){
            int ny = y+ dy[i];
            int nx = x +dx[i];
            int nz = z+1;
            if(!check_range(ny, nx)) continue;
            if(blocks[nz][ny][nx] == 1 || blocks[nz][ny][nx] == -1 || check[ny][nx][nz] >0) continue;
            q.push(make_tuple(ny,nx,nz));
            // cout<<ny<<" "<<nx<<nz<<" "<<"\n";
            check[ny][nx][nz] = check[y][x][z] + 1;
        }
    }
    return false;
}


int main(){
    cin>>n>>m;
    vector<vector<int>> block(n, vector<int>(m));
    vector<string> board(n);
    int dody, dodx;
    for(int i = 0;i<n;i++){
        cin>>board[i];
        for(int j = 0;j<m;j++){
        //   cout<<board[i][j]<<" ";
           if(board[i][j] == '.') block[i][j] = 0;
           else if(board[i][j] == 'X') block[i][j] = 1; 
           else if(board[i][j] == '*') block[i][j] = -1; 
           else if(board[i][j] == 'S'){
               dody = i;
               dodx = j;
            //   block[i][j] = 0;
           } 
           
           else if(board[i][j] == 'D'){
               block[i][j] = 3;
               cavey = i;
               cavex = j;
           }
        }
        // cout<<"\n";
    }
    // cout<<dody<<" "<<dodx<<"\n";
    // cout<<cavey<<" "<<cavex<<"\n";
    cnt = 0;
    vector<vector<int>> tempblock = block;
    
    while(true){
        blocks[cnt] = tempblock;
        // for(int i = 0;i<n;i++){
        //     for(int j = 0;j<m;j++){
        //         cout<<tempblock[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";
        if(!water(tempblock)) break;
        cnt++;
    }
    // cout<<"count: "<<cnt<<"\n";
    if(go(dody, dodx, 0)){
        for(int i = 0;i<=cnt;i++){
            if(check[cavey][cavex][i]>0){
                cout<<check[cavey][cavex][i] - 1<<"\n";
                return 0;
            }
        }
    }
    else{
        cout<<"KAKTUS"<<"\n";
    }
    return 0;
}