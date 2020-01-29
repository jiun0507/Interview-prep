//baekjoon 16954
//움직이는 미로 탈출
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

int n = 8;
int check[9][9][9];
vector<vector<int>> blocks[9];
int thold = -1;
int dy[9] = {-1, 1, 0, 0, 1, 1, -1, -1, 0};
int dx[9] = {0, 0, -1, 1, 1, -1, 1, -1, 0};

bool check_range(int y, int x){
    return y>=0 && y<n && x>=0 && x<n;
}


bool go(int a, int b, int turn){
    queue<tuple<int, int,int>> q;
    q.push(make_tuple(a, b,turn));
    check[a][b][turn] = 1;
    while(!q.empty()){
        int y, x, z;
        tie(y, x, z) = q.front();
        q.pop();
        if(z>=thold||(y== 0 && x == 7)) return true;
        for(int i = 0;i<9;i++){
            int ny = y+ dy[i];
            int nx = x +dx[i];
            int nz = min(z+1, 8);
            if(!check_range(ny, nx)) continue;
            if(blocks[nz][ny][nx] == 1 || blocks[z][ny][nx] == 1 || check[ny][nx][nz] == 1) continue;
            q.push(make_tuple(ny,nx,nz));
            check[ny][nx][nz] = 1;
            
        }
        
    }
    return false;
}

bool go2(int y, int x, int turn){
    if(blocks[turn][y][x] == 1){
        return false;
    }
    // turn = min(turn, 8);
    if(turn >= thold) return true;
    if(y==0 && x == 7) return true;
    check[y][x][turn] = 1;
    for(int i = 0;i<9;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(!check_range(ny,nx)) continue;
        if(blocks[turn][ny][nx] ==1)continue;
        if(check[ny][nx][turn+1]==1) continue;
        if(go2(ny, nx, turn +1)) return true;
    }
    return false;
}



int main(){
    vector<vector<int>> block(8, vector<int>(8));
    vector<string> board(n);
    for(int i = 0;i<8;i++){
        cin>>board[i];
        for(int j = 0;j<8;j++){
           if(board[i][j] == '.') block[i][j] = 0;
           else if(board[i][j] == '#') block[i][j] = 1; 
        }
    }

    for(int k = 0;k<=8;k++){
        blocks[k] = block;
        bool wall = false;
        for(int i = 7;i>=0;i--){
            for(int j = 0;j<8;j++){
                if(block[i][j] == 1){
                    wall = true;
                    block[i][j] = 0;
                    if(i+1<8) block[i+1][j] = 1;
                }
            }
        }
        if(!wall && thold == -1) thold = k;
        // for(int i = 0;i<8;i++){
        //     for(int j = 0;j<8;j++){
        //         printf("%d ", block[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
        
    }
    // cout<<thold<<"\n";
    cout<<go(7, 0, 0)<<"\n";

    return 0;
}