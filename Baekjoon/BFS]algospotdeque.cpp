//baekjoon 1261

//break the walls using deque BFS.
#include <iostream>
#include <queue>
#include <deque>
#include <string>
using namespace std;

int n,m;
int check[101][101];
int dist[101][101];
char map[101][101];
int movey[] = {1, -1, 0,0};
int movex[] = {0,0,-1, 1};

void BFSlist(int y, int x){
	deque<pair<int,int>> q;
	q.push_front(make_pair(y,x));
	check[y][x] = 1;
	dist[y][x] = 0;
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop_front();
		for(int i = 0;i<4;i++){
			int newy = y + movey[i];
			int newx = x + movex[i];
			if(newy >0 && newy <=m && newx >0 && newx <=n){
				if(map[newy][newx] == '0' && check[newy][newx] == 0){
					q.push_front(make_pair(newy, newx));
					check[newy][newx] = 1;
					dist[newy][newx] = dist[y][x];
				}
				else if(check[newy][newx]==0){
					q.push_back(make_pair(newy, newx));
					check[newy][newx] = 1;
					dist[newy][newx] = dist[y][x] + 1;
				}
			}
		}
	}
	return;
}
int main() {
	cin>>n>>m;
	cin.ignore();
	string st;
	for(int i = 1;i<=m;i++){
		getline(cin, st);
		for(int j = 0;j<n;j++){
			map[i][j+1] = st.at(j);
			cout<<map[i][j+1]<<" ";
		}
		cout<<"\n";
	}
	
	BFSlist(1, 1);
	cout<<dist[m][n]<<"\n";
	return 0;
}