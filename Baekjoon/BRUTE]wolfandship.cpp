//baekjoon 16956
//늑대와 양
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n,m;
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};
int check[501][501];
vector<string> farm(501);

bool check_range(int y, int x){
	return y>=0 && y<n && x>=0 && x<m;
}
int BFS(){
	queue<pair<int,int>> list;
	for(int i = 0;i<n;i++){
	    for(int j = 0;j<m;j++){
	        if(farm[i].at(j) == 'W'){ 
	            list.push(make_pair(i, j));
	            check[i][j] = 0;
	           // cout<<"YES\n";
	           }
	    }
	    
	}
	
	while(!list.empty()){
		auto cur = list.front();
		list.pop();
		int y = cur.first;
		int x = cur.second;
		int dist = check[y][x];
		for(int i = 0;i<4;i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(!check_range(ny, nx)) continue;
			if(check[ny][nx]==-1){
			    if(farm[ny][nx] == 'S'){
			        if(check[y][x] ==0) return -1;
        		    farm[y][x] = 'D';
        		    continue;
		        }
				check[ny][nx] = dist+1;
				list.push(make_pair(ny,nx));				
			}
		}
		
	}
	return 1;
}

int main() {
	cin>>n>>m;
	memset(check, -1, sizeof(check));
	for(int i = 0;i<n;i++){
		cin>>farm[i];
// 		cout<<farm[i]<<"\n";
	}
	int ans = BFS();
	if(ans == -1){
	    cout<<"0\n";
	    return 0;
	}
	cout<<"1\n";
	for(int i = 0;i<n;i++){
		cout<<farm[i]<<"\n";
	}
// 	for(int i = 0;i<n;i++){
// 		for(int j = 0;j<m;j++){
// 		    cout<<check[i][j]<<" ";
// 		}
// 		cout<<"\n";
// 	}
	
	return 0;
}