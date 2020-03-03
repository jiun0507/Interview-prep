//baekjoon 2234
//성곽
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};
int board[51][51];
int n,m;
int check[51][51];

void BFS(int r, int c, int id){
    
	queue<pair<int, int>> list;
	list.push(make_pair(r, c));
	check[r][c] = id;
    while(!list.empty()){
        int y, x;
        tie(y, x) = list.front();
        list.pop();
        // cout<<y<<" "<<x<<" "<<jump<<" "<<dist[y][x][jump]<<"\n";
        for(int l = 0; l<4; l++){
            //east north west south
            int newy = y + dy[l];
            int newx = x + dx[l];
            int cur = board[y][x];
            if(0 <= newx && newx <m && 0 <= newy && newy < n){
                if(((1<<l)&cur) != 0) continue;
                if(check[newy][newx] == -1){
                    check[newy][newx] = id;
                    list.push(make_pair(newy, newx));
                }                      
                
 
            }
        } 

    }
}

int main() {
    
    cin>>m>>n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>board[i][j];
        }
    }
    
    memset(check, -1, sizeof(check));
    int id = 1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(check[i][j] == -1){
                BFS(i, j, id);
                id++;
            }
        }
    }
    id--;
    int num[id+1];
    memset(num, 0, sizeof(num));
    int mxnum = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            num[check[i][j]] += 1;
            // cout<<check[i][j]<<" ";
        }
        // cout<<"\n";
    }
    for(int i = 1;i<=id;i++){
        // cout<<num[i]<<"\n";
        if(mxnum<num[i]) mxnum = num[i];
    }
    cout<<id<<"\n";
    cout<<mxnum<<"\n";
    int newroom = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            int cur = check[i][j];
            for(int l = 0; l<4; l++){
                //east north west south
                int newy = i + dy[l];
                int newx = j + dx[l];
                if(0 <= newx && newx <m && 0 <= newy && newy < n){
                    int neighbor = check[newy][newx];
                    if(neighbor == cur) continue;
                    if(newroom < num[neighbor] + num[cur]){
                        newroom = num[neighbor] + num[cur];
                    }
                }
            }
        }
    }
    cout<<newroom<<"\n";
	return 0;
}