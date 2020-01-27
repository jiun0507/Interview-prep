//baekjoon 16928
//snake and ladder game

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
int newx[4] = {0, 0, 1, -1};
int newy[4] = {1, -1, 0, 0};
int block[110];
int check[110];
int lens[110];

int BFS(int x){
	queue<int> list;
	list.push(x);
	int length = 0;
	lens[x] = 0;
	check[x] = 1;
	while(!list.empty()){
		int cur = list.front();
		list.pop();
		int len = lens[cur];
		// cout<<cur<<" "<<len<<"\n";
		if(cur == 100) return len;
		for(int i = 1;i<=6;i++){
			if(check[cur+i]) continue;
			check[cur+i] = 1;
			if(cur+i>100) break;
			if(block[cur+i]>0){
				if(!check[block[cur+i]]){
					check[block[cur+i]] = 1;
					list.push(block[cur+i]);
					lens[block[cur+i]] = len +1;
				}
			}
			else{
				list.push(cur+i);
				lens[cur +i] = len +1;
			}
		}
		
	}
	return -1;
}

int main() {
	cin>>n>>m;
	//snake = 1
	//ladder = 2
	for(int i = 0;i<n;i++){
		int from, to;
		cin>>from>>to;
		block[from]= to;
	}
	for(int i = 0;i<m;i++){
		int from,to;
		cin>>from>>to;
		block[from]= to;
	}
	cout<<BFS(1)<<"\n";
    return 0;
}