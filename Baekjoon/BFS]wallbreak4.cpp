//wallbreak4
//baekjoon 16946
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n,m;
int check[1001][1001];
int block[1001][1001];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool check_range(int y, int x){
    return y>=0 && y<n && x>=0 && x<m;
}
void go(int a, int b, int label){
    queue<pair<int, int>> q;
    q.push(make_pair(a,b));
    check[a][b] = 1;
    block[a][b] = label;
    while(!q.empty()){
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        block[y][x] = label;
        int d = check[y][x];
        for(int i = 0;i<4;i++){
            int ny = y+ dy[i];
            int nx = x +dx[i];
            if(!check_range(ny, nx)){
                continue;
            }
            if(check[ny][nx]>0) continue;
            if(block[ny][nx] == 0){
                q.push(make_pair(ny,nx));
                check[ny][nx] = d+1;
                
            }
        }
        
    }
    return;
}


int main(){
    cin>>n>>m;
    cin.ignore();
    int newblock[n][m];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            scanf("%1d", &block[i][j]); 
            newblock[i][j] = 0;
        }
    }
    
    int label = 2;
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(block[i][j] == 0){
                go(i,j,label);
                label++;
            }
        }
    } 
    int labellib[label]; 
    for(int i = 0;i<label;i++) labellib[i] = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            labellib[block[i][j]]+=1;
        }
    }
    
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(block[i][j] == 1){
                vector<int> cone;
                int cnt= 1;
                for(int k = 0;k<4;k++){
                    int newi = i + dy[k];
                    int newj = j + dx[k];
                    if(!check_range(newi,newj))continue;
                    if(block[newi][newj]>1) cone.push_back(block[newi][newj]);
                }
            	sort(cone.begin(),cone.end());
            	cone.erase(unique(cone.begin(),cone.end()), cone.end());
                for(int k: cone){
                    cnt+=labellib[k];
                }
                newblock[i][j] = cnt%10;
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(newblock[i][j]>0){
                 cout<<newblock[i][j];
            }
            else{
                cout<<0;
            }
    
        }
        cout<<"\n";
    }
    return 0;
}