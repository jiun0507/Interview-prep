// Example program
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n = 8;
int check[9][9][9];
vector<vector<vector<int>>> blocks;
int dy[4] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dx[4] = {0, 0, -1, 1, 1, -1, 1, -1};

bool check_range(int y, int x){
    return y>=0 && y<n && x>=0 && x<m;
}

bool go2(int y, int x, int turn){
    
}

bool go(int a, int b){
    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(a,b,0, 0));
    check[a][b][0][0] = 1;
    while(!q.empty()){
        int y, x, z, night;
        tie(y, x, z, night) = q.front();
        q.pop();
        int d = check[y][x][z][night];
        if(y== n-1 && x == m-1) return true;
        for(int i = 0;i<4;i++){
            int ny = y+ dy[i];
            int nx = x +dx[i];
            if(!check_range(ny, nx)){
                continue;
            }
            if(block[ny][nx] == 1 && check[ny][nx][z+1][1-night]==0){
                if(z != k){
                    if(night == 0){
                        q.push(make_tuple(ny,nx,z+1,1-night));
                        check[ny][nx][z+1][1-night] = d+1;                        
                    }
                }
            }
            else if(block[ny][nx] == 0 && check[ny][nx][z][1-night]==0){
                q.push(make_tuple(ny,nx,z,1-night));
                check[ny][nx][z][1-night] = d+1;
            }
        }
        if(check[y][x][z][1-night] == 0){
            q.push(make_tuple(y,x,z,1-night));
            check[y][x][z][1-night] = d+1;  
        }
    }
       
    return false;
}


int main(){
    vector<vector<int>> block(8, vector<int>(8));
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            char c;
            scanf("%1c", &c);
            if(c == '.') block[i][j] = 0;
            else if(c == '#') block[i][j] = 1;
        }
    }
    for(int k = 0;k<8;k++){
        blocks[k].push_back(block)
        for(int i = 7;i>=0;i--){
            for(int j = 0;j<8;j++){
                if(blocks[i][j] == '1'){
                    blocks[i][j] == '0'
                    if(i+1<8) block[i+1][j] = 1;
                }
            }
        }
        
    }
    return 0;
}