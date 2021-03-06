// Example program
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n,m;
int check[1001][1001][2];
int block[1001][1001];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool check_range(int y, int x){
    return y>=0 && y<n && x>=0 && x<m;
}
bool go(int a, int b){
    queue<tuple<int, int,int>> q;
    q.push(make_tuple(a,b, 0));
    check[a][b][0] = 1;
    while(!q.empty()){
        int y, x, z;
        tie(y, x, z) = q.front();
        q.pop();
        int d = check[y][x][z];
        if(y== n-1 && x == m-1) return true;
        for(int i = 0;i<4;i++){
            int ny = y+ dy[i];
            int nx = x +dx[i];
            if(!check_range(ny, nx)){
                continue;
            }
            if(check[ny][nx][z]>0) continue;
            if(block[ny][nx] == 1){
                if(z == 0){
                    q.push(make_tuple(ny,nx,1));
                    check[ny][nx][1] = d+1;
                }
            }
            else if(block[ny][nx] == 0){
                if(!z){
                    q.push(make_tuple(ny,nx,0));
                    check[ny][nx][0] = d+1;
                }
                else{
                    q.push(make_tuple(ny,nx,1));
                    check[ny][nx][1] = d+1;
                }
            }
        }
        
    }
    return false;
}


int main(){
    cin>>n>>m;
    cin.ignore();
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            scanf("%1d", &block[i][j]);  
            
        }
        
    }
    
    if(go(0,0)){
        if(check[n-1][m-1][0]>0) cout<<check[n-1][m-1][0]<<"\n";
        else{
            cout<<check[n-1][m-1][1]<<"\n";
        }
    }
    else{
        cout<<-1<<"\n";
    }
 
    return 0;
}