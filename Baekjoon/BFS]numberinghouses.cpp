//baekjoon 2667
//단지번호 붙이기
//DFS and BFS given nodes in the form of 2D array

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int n;

int check[25][25];
int houses[25][25];
pair<int,int> direction[4] = {{1,0},{0,1},{-1,0},{0,-1}};
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
//two ways of storing directions

void DFSlist(int y, int x, int groupID){
	check[y][x] = groupID;
	for(int i = 0; i<4;i++){
		int newy= y + direction[i].first;
		int newx= x + direction[i].second;
		if(newy<0 ||newy>=n||newx<0||newx>=n) continue;
		if(check[newy][newx] == 0 && houses[newy][newx]==1){
			DFSlist(newy, newx, groupID);
		}
	}
	return;
}


void BFSlist(int y, int x, int groupID){
	queue<pair<int,int>> q;
	q.push(make_pair(y, x));
	check[y][x] = groupID;
	while(!q.empty()){
		pair<int,int> coor = q.front();
		q.pop();
		y = coor.first;
		x = coor.second;
		for(int i = 0;i<4;i++){
			int newy = y + direction[i].first;
			int newx = x + direction[i].second;
			if(newy <0|| newx<0||newy>=n||newx>=n) continue;
			if(!check[newy][newx] && houses[newy][newx] == 1){
				q.push(make_pair(newy, newx));
				check[newy][newx] = groupID;
			}
		}
	}
	return;
}

int main() {
	cin>>n;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			scanf("%1d", &houses[i][j]);
		}
	}
	int number = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(houses[i][j]==1 && check[i][j] == 0){
				number++;
				DFSlist(i,j,number);
			}
		}
	}

	cout<<number<<"\n";
	int numbers[number+1] = {0};
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			numbers[check[i][j]]+=1;
		}
	}
	sort(numbers+1, numbers+number+1);
	for(int i =1;i<=number;i++){
		cout<<numbers[i]<<"\n";
	}
	return 0;
	
}