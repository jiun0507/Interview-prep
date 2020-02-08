//baekjoon 12100
//easy

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int n;
int newx[4] = {0, 0, 1, -1};
int newy[4] = {1, -1, 0, 0};

vector<int> generate(int k){
	vector<int> mask;
	for(int i = 0;i<5;i++){
		int temp = k&3;
		mask.push_back(temp);
		k = k>>2;
	}
	return mask;
}
bool check_range(int y, int x){
	return y>=0 && y<n && x>=0 && x<n;
}
bool simulate(vector<vector<pair<int,bool>>> &b, int dir, int i, int j){	
	int cur = b[i][j].first;
	int ni = i + newy[dir];
	int nj = j + newx[dir];
	if(!check_range(ni, nj)){
		return false;	
	} 
	int next = b[ni][nj].first;
	if(next == cur){
		if(b[ni][nj].second || b[i][j].second){
			return false;
		}
		else{
			b[ni][nj].first *= 2;
			b[i][j].first = 0;
			b[ni][nj].second = true;
			return true;
		}
	}
	else if(next == 0){
		int temp = b[ni][nj].first;
		b[ni][nj].first = b[i][j].first;
		//second까지 바꿔주는게 중요함.
		b[ni][nj].second = b[i][j].second;
		b[i][j].first = 0;
		return true;
	}
	return false;
}
int go(vector<int> dir, vector<vector<int>> &b){
	vector<vector<pair<int, bool>>> newb(n, vector<pair<int,bool>>(n));
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			newb[i][j].first = b[i][j];
		}
	}

	for(int k:dir){
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				newb[i][j].second = false;
			}
		}
		bool moved = true;
		while(moved){
			moved = false;
			if(k == 0){
				for(int i = n-1;i>=0;i--){
					for(int j = 0;j<n;j++){
						if(newb[i][j].first == 0) continue;
						if(simulate(newb, k, i, j)){
							moved = true;
						}
					}
				}	
			}
			if(k == 1){
				for(int i = 0;i<n;i++){
					for(int j = 0;j<n;j++){
						if(newb[i][j].first == 0) continue;
						if(simulate(newb, k, i, j)){
							moved = true;
						}
					}
				}	
			}
			if(k == 2){
				for(int j = n-2;j>=0;j--){
					for(int i = 0;i<n;i++){
						if(newb[i][j].first == 0) continue;
						if(simulate(newb, k, i, j)){
							moved = true;
						}
					}
				}	
			}
			if(k == 3){
				for(int j = 1;j<n;j++){
					for(int i = 0;i<n;i++){
						if(newb[i][j].first == 0) continue;
						if(simulate(newb, k, i, j)){
							moved = true;
						}
					}
				}	
			}
		}
		// for(int i = 0;i<n;i++){
		// 	for(int j = 0;j<n;j++){
		// 		cout<<newb[i][j].first<<" ";
		// 	}
		// cout<<"\n";
		// }
	}
	int ans = -1;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(ans == -1 || ans<newb[i][j].first){
				ans = newb[i][j].first;
			}
		}
	}	
	return ans;
}


int main() {
	cin>>n;
	vector<vector<int>> blocks(n, vector<int> (n));
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cin>>blocks[i][j];	
			// cout<<blocks[i][j]<<" ";
		}
		// cout<<"\n";
	}
	vector<int> dir;
	int ans = -1;
	for(int i = 0;i<(1<<10);i++){
		vector<int> dir = generate(i);
		vector<vector<int>> newb = blocks;
		int result = go(dir, newb);
		if(ans == -1 || result>ans) ans = result;
	}
	cout<<ans<<"\n";
	
    return 0;
}