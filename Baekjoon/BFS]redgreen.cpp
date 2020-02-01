//
//baekjoon 10026
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
int check[101][101];
int check2[101][101];
int block[101][101];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool check_range(int y, int x){
    return y>=0 && y<n && x>=0 && x<n;
}
void go(int a, int b, int label, int letter){
    queue<pair<int, int>> q;
    q.push(make_pair(a,b));
    check[a][b] = label;
    while(!q.empty()){
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0;i<4;i++){
            int ny = y+ dy[i];
            int nx = x +dx[i];
            if(!check_range(ny, nx)) continue;
            if(check[ny][nx]>0) continue;
            if(block[ny][nx] == letter){
                q.push(make_pair(ny,nx));
                check[ny][nx] = label;
            }
        }
    }
    return;
}


int main(){
    cin>>n;
    cin.ignore();
    vector<string> a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(a[i][j] == 'R'){
                block[i][j] = 1;
            }
            else if(a[i][j] == 'G'){
                block[i][j] = 2;
            }
            else if(a[i][j] == 'B'){
                block[i][j] =3;
            }
        }
    } 
    int label = 1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(check[i][j] == 0){
                go(i, j, label, block[i][j]);
                label++;
            }
        }
    }
    cout<<label-1<<" ";
    memset(check, 0, sizeof(check));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(block[i][j] == 1) block[i][j] = 2;
            check[i][j] = 0;
            // cout<<block[i][j]<<" ";
        }
        // cout<<"\n";
    }
    label = 1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(check[i][j] == 0){
                go(i, j, label, block[i][j]);
                label++;
            }
        }
    }
    cout<<label-1<<"\n";
    return 0;
}