//baekjoon 6087
//레이저 통신
#include <iostream>
#include <tuple>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
int board[100][100];
int n,m;
int d[100][100];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int fy ,fx , sy , sx ;
bool check_range(int y, int x){
    return y>=0 && y<n && x>=0 && x<m;
}
void lifesaver(int a, int b){
    memset(d, -1, sizeof(d));
    queue<pair<int,int>> q;
    q.push(make_pair(a, b));
    d[a][b] = 0;
    while(!q.empty()){
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0;i<4;i++){
            for(int j = 0;j<100;j++){
                int nx = x+ j*dx[i];
                int ny = y+ j*dy[i];
                if(!check_range(ny, nx)) break;
                if (board[ny][nx] == 1) break;
                if (d[ny][nx] == -1) {
                    d[ny][nx] = d[y][x] + 1;
                    q.push(make_pair(ny,nx));
                }
            }
        }
    }
    return ;
}

int main() {
    cin>>m>>n;
    fy =fx = sy = sx = -1;
    vector<string> a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
        for(int j =0;j<m;j++){
            if(a[i][j] == '.') board[i][j] = 0;
            else if(a[i][j] == 'C'){
                if(fy == -1){
                    fy = i; fx = j;
                }
                else{
                    sy = i; sx = j;
                }
                board[i][j] = 0;
            }
            else if(a[i][j] == '*') board[i][j] = 1;
        }
    }
    lifesaver(fy, fx);
    cout<<d[sy][sx]-1<<"\n";
    return 0;
}