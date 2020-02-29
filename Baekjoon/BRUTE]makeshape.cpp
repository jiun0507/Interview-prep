//baekjoon 16932
//모양 만들기
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int board[1001][1001];
int n, m;
int check[1001][1001];
int idcnt[100000];

bool check_range(int y, int x){
    return y>=0 && y<n && x>=0 && x<m;
}

int BFSwater(int r, int c, int id){
    
	queue<pair<int,int>> list;
	list.push(make_pair(r, c));
	check[r][c] = id;
    while(!list.empty()){
        auto p = list.front();
        int y = p.first;
        int x = p.second;
        list.pop();
        for(int dir = 0;dir<4;dir++){
            int newy = y + dy[dir];
            int newx = x + dx[dir];
            if(check_range(newy, newx) && check[newy][newx] == 0 && board[newy][newx] == 1){
                check[newy][newx] = id;
                list.push(make_pair(newy, newx));
            }
        }
        
    }
	return 0;
}

int main() {
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>board[i][j];
        }
    }
    int id = 1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(check[i][j] == 0 && board[i][j] == 1){
                BFSwater(i, j, id);
                id++;
            }
        }
    }
    memset(idcnt, 0, sizeof(idcnt));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            idcnt[check[i][j]] += 1;
        }
    }
    set<int> stored;
    // memset(stored, 0, sizeof(stored));
    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            int cnt = 1;
            if(board[i][j] == 0){
                for(int dir = 0;dir<4;dir++){
                    int newy = i + dy[dir];
                    int newx = j + dx[dir];
                    int curid = check[newy][newx];
                    if(curid != 0){
                        if(stored.find(curid) == stored.end()){
                            cnt += idcnt[curid];
                            stored.insert(curid);
                        }
                    }
                }
            }
            if(ans<cnt) ans = cnt;
            stored.clear();
        }
    }
    cout<<ans<<"\n";
	return 0;
}