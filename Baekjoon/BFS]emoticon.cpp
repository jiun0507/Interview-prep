//baekjoon 14226

// 2D BFS problem -> emoji
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int s;
int check[1001][1001];
int cnt[1001][1001];

int BFSlist(){
	queue<pair<int,int>> q;
	q.push(make_pair(1,0));
	check[1][0] = 1;
	cnt[1][0] = 0;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(x == s){
			return cnt[x][y];
		}
		if(x>0 && !check[x-1][y]){
			q.push(make_pair(x-1, y));
			check[x-1][y] = 1;
			cnt[x-1][y] = cnt[x][y] +1;
		}
		if(x+y<=1000 &&!check[x+y][y]){
			q.push(make_pair(x+y,y));
			check[x+y][y] = 1;
			cnt[x+y][y] = cnt[x][y]+1;
		}
		if(!check[x][x]){
			q.push(make_pair(x, x));
			check[x][x] = 1;
			cnt[x][x] = cnt[x][y] +1;	
		}
	}
	return -1;
}
int main() {
	cin>>s;
	int time = BFSlist();
	cout<<time<<"\n";
	return 0;
}