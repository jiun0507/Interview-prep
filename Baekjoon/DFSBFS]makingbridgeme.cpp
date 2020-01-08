//baekjoon 2146
//다리 만들기
//틀림


#include <iostream>
#include <queue>

using namespace std;

int n;
int check[101][101];
int map[101][101];
int dist[101][101];
int movey[4] = {0,0,-1,1};
int movex[4] = {-1, 1,0,0};


int BFSlist(int groupID){
	int length = 0;
	queue<pair<int,int>> q;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(check[i][j] == groupID){
				q.push(make_pair(i, j));
				dist[i][j] = length;
			}
			else{
				dist[i][j] = -1;
			}
		}
	}
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for(int i = 0;i<4;i++){
			int newy = y + movey[i];
			int newx = x + movex[i];
			if(newy >=0 && newx >=0 && newy<n && newx<n){
				if(dist[newy][newx] == -1){
					q.push(make_pair(newy, newx));
					dist[newy][newx] = dist[y][x] + 1;
				}
			}
		}
	}
	
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cin>>map[i][j];
		}
	}
    
	int number = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if (map[i][j] == 1 && check[i][j] == 0) {
                check[i][j] == ++number;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for (int k=0; k<4; k++) {
                        int newy = y+movey[k];
                        int newx = x+movex[k];
                        if (0 <= newx && newx < n && 0 <= newy && newy < n) {
                            if (map[newy][newx] == 1 && check[newy][newx] == 0) {
                                check[newy][newx] = number;
                                q.push(make_pair(newy,newx));
                            }
                        }
                    }
                }
            }
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cout<<check[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<number<<"\n";
	int ans = -1;
	for(int i = 1;i<=number;i++){
		BFSlist(i);
	}

	return 0;
}