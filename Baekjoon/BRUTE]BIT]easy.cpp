//baekjoon 12100
//easy

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int n;
int mini = 1000000001;
int newx[4] = {0, 0, 1, -1};
int newy[4] = {1, -1, 0, 0};

bool found = false;

vector<int> generate(int k){
	vector<int> mask;
	for(int i = 0;i<5;i++){
		int temp = k&3;
		mask.push_back(temp);
		k = k>>2;
	}
	return mask;
}
//in the hole = 1
//blocked = 2
//moved = 0
bool check_range(int y, int x){
	return y>=0 && y<n && x>=0 && x<n;
}
bool simulate(vector<vector<pair<int,bool>>> &b, int dir){	
	int dy = newy[dir];
	int dx = newx[dir];
	bool moved = false;
	for(int i = 0; i<n;i++){
		for(int j = 0;j<n;j++){
			bool blocked = false;
			bool merge = false;
			while(!blocked){
				int cur = b[i][j].first;
				if(cur == 0) continue;
				int ni = i + dy;
				int nj = j + dx;
				if(!check_range(ni, nj)){
					cout<<"checked"<<"\n";
					break;	
				} 
				int next = b[ni][nj].first;
				if(next == cur){
					b[ni][nj].first *= 2;
					b[i][j].first = 0;
					blocked = true;
					moved = true;
				}
				if(next == 0){
					int temp = b[ni][nj].first;
					b[ni][nj].first = b[i][j].first;
					b[i][j].first = temp;
					i = ni;	j = nj;
					blocked = true;
					moved = true;
				}
				if(next != cur){
					blocked = true;
				}
			}
		}
	}
	return moved;
}
int go(vector<int> dir, vector<vector<int>> &b){
	int cnt = 0;
	vector<vector<pair<int, bool>>> newb(n, vector<pair<int,bool>>(n));
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			newb[i][j].first = b[i][j];
		}
	}
	for(int k:dir){
		cnt++;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				newb[i][j].second = false;
			}
		}
		bool moved = true;
		
	}

	return cnt;
}


int main() {
	cin>>n;
	vector<vector<int>> blocks(n, vector<int> (n));
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cin>>blocks[i][j];	
			cout<<blocks[i][j]<<" ";
		}
		cout<<"\n";
	}
	int ans = -1;
	for(int i = 0;i<(1<<10);i++){
		vector<int> dir = generate(i);
	}
	vector<vector<pair<int, bool>>> newblock(n, vector<pair<int,bool>>(n));
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			newblock[i][j].first = blocks[i][j];
		}
	}
	cout<<simulate(newblock, 2)<<"\n";
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cout<<blocks[i][j]<<" ";
		}
		cout<<"\n";
	}	

    return 0;
}