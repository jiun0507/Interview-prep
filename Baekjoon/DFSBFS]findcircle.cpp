//baekjoon 1260

//DFS and BFS implemented using edge list(count array) and linked list(vector)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int m,n;
int check[51][51];
char board[51][51];
int movey[4] = {0,0,-1,1};
int movex[4] = {-1, 1,0,0};

bool DFSlist(int y, int x, char c, int distance){
	check[y][x] = distance;
	for(int i = 0; i<4;i++){
		int newy= y + direction[i].first;
		int newx= x + direction[i].second;
		if(newy<0 ||newy>=n||newx<0||newx>=n) continue;
		else if(check[newy][newx] == 0 && board[newy][newx]==c){
			if(DFSlist(newy, newx, c, distance + 1)){
				return true;
			}
		}
		else if(check[newy][newx] == 1 && board[newy][newx] == c){
			return true;
		}
	}
	return false;
}

int main() {

	cin>>m>>n;
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			cin>>board[i][j];
		}
	}
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			if(check[i][j] ==0 && DFS(i,j,board[i][j], 1)){
				cout<<"Yes"<<"\n";
				return 0;
			}
		}
	}
	
	cout<<"No"<<"\n";
	
	return 0;
}