//baekjoon 3055
//탈출
#include <iostream>
#include <tuple>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
int water[50][50];
int d[50][50];
int n,m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int sy, sx, doy, dox;
bool check_range(int y, int x){
    return y>=0 && y<n && x>=0 && x<m;
}

int main() {
    cin>>n>>m;
    vector<string> a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    int water[n][m];
    memset(water, -1, sizeof(water));
    queue<pair<int, int>> q;
    for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            if(a[i][j] == '*'){
                water [i][j] = 0; 
                q.push(make_pair(i, j));
            }
            else if(a[i][j] == 'S'){
                sy =i;
                sx = j;
            }
            else if(a[i][j] == 'D'){
                doy = i; dox = j;
            }

        }
    }
    while(!q.empty()){
        int y, x;
        tie(y,x) = q.front();
        q.pop();
        for(int i = 0;i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(!check_range(ny ,nx)) continue;
            if(a[ny][nx] == 'D' || a[ny][nx] == 'X' || water[ny][nx] != -1) continue;
            water[ny][nx] = water[y][x] + 1;
            q.push(make_pair(ny ,nx));
        }
    }
    q.push(make_pair(sy, sx));
    memset(d, -1, sizeof(d));
    d[sy][sx] = 0;
    
    while(!q.empty()){
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        // if(y == doy && x == dox) break;
        for(int i = 0;i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(!check_range(ny ,nx)) continue;
            if(d[ny][nx] != -1 || a[ny][nx] == 'X') continue;
            if(water[ny][nx] != -1 && d[y][x] + 1>=water[ny][nx]) continue;
            d[ny][nx] = d[y][x] + 1;
            q.push(make_pair(ny, nx));
        }
    }   
    // for(int i = 0;i<n;i++){
    //     for(int j =0;j<m;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // for(int i = 0;i<n;i++){
    //     for(int j =0;j<m;j++){
    //         cout<<water[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    // for(int i = 0;i<n;i++){
    //     for(int j =0;j<m;j++){
    //         cout<<d[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<sy<<" "<<sx<<"\n";
    // cout<<doy<<" "<<dox<<"\n";
    // if(d[doy][dox] != -1){
    if(d[doy][dox] == -1){
        cout<<"KAKTUS"<<"\n";
    }
    else{
         cout<<d[doy][dox]<<"\n";
    }
 
    // }
    return 0;
}