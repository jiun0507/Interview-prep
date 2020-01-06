//baekjoon 2178
//DFS and BFS implemented using edge list(count array) and linked list(vector)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int n,m;
int check[100][100];
int road[100][100];
int movey[4] = {-1, 1, 0, 0};
int movex[4] = {0, 0, 1, -1};



void BFSlist(int y, int x){
	int length = 1;
	queue<pair<int,int>> q;
	q.push(make_pair(y, x));
	check[y][x] = length;
	while(!q.empty()){
		pair<int,int> coor = q.front();
		q.pop();
		y = coor.first;
		x = coor.second;
		length = check[y][x] +1;
		for(int i = 0;i<4;i++){
			int newy = y + movey[i];
			int newx = x + movex[i];
			if(newy <0|| newx<0||newy>=m||newx>=n) continue;
			if(!check[newy][newx] && road[newy][newx] == 1){
				q.push(make_pair(newy, newx));
				check[newy][newx] = length;
			}
		}
	}
	return;
}


int main() {

	cin>>m>>n;
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			scanf("%1d", &road[i][j]);
		}
	}
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			if(road[i][j]==1 && check[i][j] == 0){
				BFSlist(i,j);
			}
		}
	}
	cout<<check[m-1][n-1]<<"\n";

	return 0;
}