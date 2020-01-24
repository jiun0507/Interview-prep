//baekjoon 14500

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int n,m;
int maxi = -1000000001;
int newx[4] = {0, 0, 1, -1};
int newy[4] = {1, -1, 0, 0};
int blocks[500][500];
int check[500][500];

int go(int sum, int y, int x, int cnt){
	if(cnt == 4){
		check[y][x] = 0;
		return sum;
	}
	check[y][x] = 1;
	int ans = 0;
	for(int i = 0;i<4;i++){
		int y2 = y + newy[i];
		int x2 = x + newx[i];
		if(y2 < 0 || y2==n || x2<0 || x2==m || check[y2][x2] == 1){
			continue;
		}
		int temp = go(sum + blocks[y2][x2], y2, x2, cnt + 1);
		if(ans<temp) ans = temp;
	}
	check[y][x] = 0;
	return ans;
}
int goV2(int sum, int y, int x, int cnt){
	if(cnt == 4){
		return sum;
	}
	if(y < 0 || y==n || x<0 || x==m || check[y][x] == 1){
		return 0;
	}
	check[y][x] = 1;
	int ans = 0;
	for(int i = 0;i<4;i++){
		int y2 = y + newy[i];
		int x2 = x + newx[i];
		int temp = go(sum + blocks[y][x], y2, x2, cnt + 1);
		if(ans<temp) ans = temp;
	}
	check[y][x] = 0;
	return ans;
}

//takes care of T shapes(is not covered by go recursion function)
int go2(int y, int x){
	
	int maxi = 0;
	for(int i = 0;i<4;i++){
		int sum = blocks[y][x];
		for(int j = 0;j<4;j++){
			if(i != j){
				int y2 = y + newy[j];
				int x2 = x + newx[j];
				if(y2<0 || y2==n || x2<0 || x2==m) break;
				sum += blocks[y2][x2];
			}
			if(maxi < sum) maxi = sum;
		}
	}
	return maxi;
}

int main() {
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin>>blocks[i][j];
		}
	}

	int ans = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			int temp = go(blocks[i][j], i, j, 1);
			int temp2 = go2(i, j);
			if(ans<temp2) ans = temp2;
			if(ans<temp) ans = temp;
			
		}
	}	
	cout<<ans<<"\n";
	
    return 0;
}