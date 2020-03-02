//baekjoon 2151
//거울 설치
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int board[51][51];
int n;

vector<vector<int>> BFSmonkey(int r, int c, int id){
    vector<vector<int>> dist(n, vector<int>(n,-1));
	queue<pair<int, int>> list;
	list.push(make_pair(r, c));
	dist[r][c] = 0;
    while(!list.empty()){
        
        int y, x;
        tie(y, x) = list.front();
        list.pop();
        for(int l = 0; l<4; l++){
            int newy = y + dy[l];
            int newx = x + dx[l];
            if(0 <= newx && newx <n && 0 <= newy && newy < n){
                if(board[newy][newx] == -1) continue;
                if(dist[newy][newx] == -1){
                    dist[newy][newx] = dist[y][x]+ 1;
                    list.push(make_pair(newy, newx));
                }                      
                
 
            }
        } 

    }
    return dist;
}

int main() {
    
    cin>>n;
    vector<pair<int,int>> mirrors;
    int y1, x1, y2, x2;
    int start = -1;
    int end = -1;
    vector<string> a;
    for(int i = 0;i<n;i++){
        string buf;
        cin>>buf;
        a.push_back(buf);
        for(int j = 0;j<n;j++){
            if(buf.at(j) == '.'){
                board[i][j] = 0;
            }
            else if(buf.at(j) == '!'){
                board[i][j] = mirrors.size();
                mirrors.push_back(make_pair(i,j));
            }
            else if(buf.at(j) == '#'){
                if(start != -1){
                    end = mirrors.size();
                }
                else{
                    start = mirrors.size();
                }
                board[i][j] = mirrors.size();
                mirrors.push_back(make_pair(i,j));
            }
            else if(buf.at(j) == '*'){
                board[i][j] = -1;
            }
        }
    }
    int connect[mirrors.size()][mirrors.size()];

    memset(connect, 0, sizeof(connect));
    for(int i = 0;i<mirrors.size();i++){
        auto p = mirrors[i];
        for(int j =0 ;j<4;j++){
            int newy = p.first + dy[j];
            int newx = p.second + dx[j];
            while(newy>=0 && newy <n && newx >=0 && newx <n){
                if(a[newy][newx] == '*') break;
                if(a[newy][newx] == '#' || a[newy][newx] == '!'){
                    connect[board[p.first][p.second]][board[newy][newx]] = 1;
                }
                newy += dy[j];
                newx += dx[j];
            }
        }
    }
    int dist[mirrors.size()];
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int i = 0;i<mirrors.size();i++){
            if(connect[p][i] == 1 && dist[i] == -1){
                dist[i] = dist[p] + 1;
                q.push(i);
            }
        }
    }
    cout<<dist[end]-1<<"\n";
    

    
	return 0;
}