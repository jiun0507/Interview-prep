//baekjoon 7576

//DFS and BFS implemented using edge list(count array) and linked list(vector)
//when are the tomatoes ripe?

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int n,m;
int check[1001][1001];
int tomato[1001][1001];
int movey[4] = {-1, 1, 0, 0};
int movex[4] = {0, 0, 1, -1};



void BFSlist(){
	int length = 1;
	queue<pair<int,int>> q;
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			if(tomato[i][j] == 1){
				q.push(make_pair(i, j));
				tomato[i][j] = length;
			}
		}
	}
	
	while(!q.empty()){
		pair<int,int> coor = q.front();
		q.pop();
		int y = coor.first;
		int x = coor.second;
		length = tomato[y][x] +1;
		for(int i = 0;i<4;i++){
			int newy = y + movey[i];
			int newx = x + movex[i];
			if(newy <0|| newx<0||newy>=m||newx>=n) continue;
			if(tomato[newy][newx] == 0){
				q.push(make_pair(newy, newx));
				tomato[newy][newx] = length;
			}
		}
	}
	return;
}


int main() {

	cin>>n>>m;
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			cin>>tomato[i][j];
			
		}
	}
	// for(int i = 0;i<m;i++){
	// 	for(int j = 0;j<n;j++){
	// 		cout<<tomato[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	BFSlist();
	
	int maximum = 0;
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			if(tomato[i][j] == 0){
				cout<<"-1"<<"\n";
				return 0;
			}
			if(tomato[i][j]>maximum){
				maximum = tomato[i][j];
			}
		}
	}
	cout<<maximum-1<<"\n";
	return 0;
}