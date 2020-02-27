//baekjoon 16988
//Baduuuuuk 2
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n,m;  
int check[20][20];
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

bool check_range(int y, int x){
	return y>=0 && y<n && x>=0 && x<m;
}
int BFS(int r, int c, vector<vector<int>> &board){
	queue<pair<int,int>> list;
	list.push(make_pair(r, c));
	int cnt = 0;
	check[r][c] = 1;
	bool zero = false;
	while(!list.empty()){
		auto cur = list.front();
		list.pop();
		cnt++;
		int y = cur.first;
		int x = cur.second;
// 		cout<<y<<" "<<x<<"\n";
		for(int i = 0;i<4;i++){
			int ny = y +dy[i];
			int nx = x + dx[i];
			if(!check_range(ny, nx) || check[ny][nx] == 1) continue;
			if(board[ny][nx] == 0){
			    zero =true;
			    continue;
			}
			if(board[ny][nx] == 1) continue;
			list.push(make_pair(ny,nx));
			check[ny][nx] = 1;
		}
		
	}
	if(zero) return 0;
	return cnt;
}
int main(void){
    cin>>n>>m;
    vector<vector<int>> board(n, vector<int>(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>board[i][j];
        }
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            for(int k = 0;k<n;k++){
                for(int v = 0;v<m;v++){
                    if(board[i][j] != 0 || board[k][v] != 0) continue;
                    memset(check, 0, sizeof(check));
                    board[i][j] = 1;
                    board[k][v] = 1;
                    int sum = 0;
                    int num =0 ;
                    for(int a =0 ;a<n;a++){
                        for(int b = 0;b<m;b++){
                            if(board[a][b] == 2 && check[a][b] == 0){
                                // cout<<num<<" : "<<a<<" "<<b<<" ";
                                sum += BFS(a, b, board);
                                // cout<<sum<<"\n";
                                num++;
                            }
                        }
                    }
                    // cout<<num<<"\n";
                    if(ans<sum) ans = sum;
                    board[i][j] = 0;
                    board[k][v] = 0;                    
                }
            }
        }
    }
    cout<<ans<<"\n";
}