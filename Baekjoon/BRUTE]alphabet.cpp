//baekjoon 1987

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int n,m;
int maxi = -1000000001;
int newx[4] = {0, 0, 1, -1};
int newy[4] = {1, -1, 0, 0};
int block[21][21];
int check[30];

bool check_range(int y, int x){
	if(y<0 || y==n || x<0 || x== n) return false;
	return true;
}

int go(int y, int x, int length){
	check[block[y][x]] = 1;
	int ans = length;
	for(int i = 0;i<4;i++){
		int y2 = y + newy[i];
		int x2 = x + newx[i];
		if(y2 < 0 || y2==n || x2<0 || x2==m || check[block[y2][x2]] == 1){
			continue;
		}
		int temp = go(y2, x2, length + 1);
		if(ans<temp) ans = temp;
	}
	check[block[y][x]] = 0;
	return ans;
}

int main() {
	cin>>n>>m;
	cin.ignore();
	for(int i = 0;i<n;i++){
		string line;
		getline(cin,line);
		for(int j = 0;j<line.size();j++){
			block[i][j] = line.at(j)-'A';
		}
	}
	cout<<go(0, 0, 1)<<"\n";
	
    return 0;
}