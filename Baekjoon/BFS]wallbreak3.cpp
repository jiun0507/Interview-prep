//baekjoon 16933
//wallbreak3 벽 부수기 3
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n,m,k;
int check[1001][1001][11][2];
int block[1001][1001];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool check_range(int y, int x){
    return y>=0 && y<n && x>=0 && x<m;
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
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            scanf("%1d", &block[i][j]);  
            
        }
        
    }
    int ans = -1;
    if(go(0,0)){
        for(int i = 0;i<=k;i++){
            for(int j = 0;j<2;j++){
                int temp = check[n-1][m-1][i][j];
                if(temp >0){
                    if(ans == -1||temp <ans) ans = temp;
                }               
            }
        }
        printf("%d\n", ans);
        return 0;
        
    }
    else{
        printf("-1");
    }
    
    // if(go(0,0)){
    //     if(check[n-1][m-1][0]>0) cout<<check[n-1][m-1][0]<<"\n";
    //     else{
    //         cout<<check[n-1][m-1][1]<<"\n";
    //     }
    // }
    // else{
    //     cout<<-1<<"\n";
    // }
 
    return 0;
}