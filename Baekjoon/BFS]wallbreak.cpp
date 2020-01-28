//baekjoon 2206
//벽 부수고 이동하기
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int check[1001][1001][2];
vector<string> walls;
int block[1001][1001];
int dist[1001][1001][2];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool check_range(int y, int x){
    return y>=0 && y<n && x>=0 && x<m;
}
bool go(int a, int b){
    queue<pair<int,int>> q;
    q.push(make_pair(a,b));
    check[a][b][0] = 1;
    dist[a][b][0] = 1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int y = cur.first;
        int x = cur.second;
        int d = 0;
        int used = 1;//0 if not broken wall before
        if(y== n-1 && x == m-1) return true;
        if(check[y][x][0]){
            d = dist[y][x][0]; 
            used = 0;
        }
        else{
            d= dist[y][x][1];
        }
        for(int i = 0;i<4;i++){
            int ny = y+ dy[i];
            int nx = x +dx[i];
            if(!check_range(ny, nx)){
                continue;
            }
            if(check[ny][nx][used]) continue;
            if(block[ny][nx] == 1){
                if(used == 0){
                    q.push(make_pair(ny,nx));
                    check[ny][nx][1] = 1;
                    dist[ny][nx][1] = d+1;
                }
            }
            else if(block[ny][nx] == 0){
                if(!used){
                    q.push(make_pair(ny,nx));
                    check[ny][nx][0] = 1;
                    dist[ny][nx][0] = d+1;
                }
                else{
                    q.push(make_pair(ny,nx));
                    check[ny][nx][1] = 1;
                    dist[ny][nx][1] = d+1;
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
        string temp;
        getline(cin, temp);
        walls.push_back(temp);
        for(int j = 0;j<m;j++){
            block[i][j] = walls[i].at(j) - '0';
        }
    }
    
    // for(int i = 0;i<n;i++){
    //     for(int j = 0;j<m;j++){
    //         cout<<check[i][j][1]<<" ";
    //     }
    //     cout<<"\n";
    // }
    if(go(0,0)){
        if(check[n-1][m-1][0]) cout<<dist[n-1][m-1][0];
        else{
            cout<<dist[n-1][m-1][1];
        }
    }
    else{
        cout<<-1<<"\n";
    }
    return 0;
}