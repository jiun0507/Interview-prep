//baekjoon 9663

#include <iostream>
#include <vector>
using namespace std;
int n;
int ans = 0;
int check_dig[15][15];
int check_col[15][15];
int dy[2] = {1, -1};
int dx[2] = {0, 0};
int dy2[4] = {1, 1, -1,-1};
int dx2[4] = {-1, 1, 1, -1};

void queen(int row, int col, int val){
	for(int i = 0;i<2;i++){
		for(int j = 0;j<n;j++){
			int newy = row + dy[i]*j;
			int newx = col + dx[i]*j;
			if(newy<0 || newy ==n || newx < 0 || newx == n) break;
			check_col[newy][newx] += val;
		}
	}
	for(int i = 0;i<4;i++){
		for(int j = 0;j<n;j++){
			int newy = row + dy2[i]*j;
			int newx = col + dx2[i]*j;
			if(newy<0 || newy ==n || newx < 0 || newx == n) break;
			check_dig[newy][newx] += val;
		}
	}
	return;
}

void calc(int row){
	if(row == n){
		ans +=1;
		return;
	}
	for(int i = 0;i<n;i++){
		if(check_dig[row][i] != 0 || check_col[row][i] != 0) continue;
		queen(row, i,1);
		calc(row+1);
		queen(row, i, -1);
	}
	return;
}

int main() {
	cin>>n;
	// queen(1, 0, 1);
	// queen(1, 0, 0);
	// for(int i = 0;i<n;i++){
	// 	for(int j = 0;j<n;j++){
	// 		cout<<check_dig[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	calc(0);
	cout<<ans<<"\n";
	return 0;
}