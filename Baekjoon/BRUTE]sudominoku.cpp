//baekjoon 4574

#include <iostream>
#include <vector>
using namespace std;
int n;
int ans = 0;
int pairs[10][10];
int squares[9][10];
int check_row[9][10];
int check_col[9][10];
int block[9][9];
vector<pair<int,int>> empty; 
 
bool go(int row, int col, int index){
	if(index == empty.size()){
		return true;
	}
	for(int i = 1;i<=9;i++){
		int row1 = row / 3;
		int col1 = col / 3; 
		if(check_row[row][i] == 0 && check_col[col][i] == 0 && squares[row1*3 + col1][i] == 0){
			check_row[row][i] = 1;
			check_col[col][i] = 1;
			squares[row1*3 + col1][i] = 1;
			block[row][col] = i;
			if(go(empty[index+1].first, empty[index+1].second, index + 1)){
				return true;
			}
			block[row][col] = 0;
			check_row[row][i] = 0;
			check_col[col][i] = 0;
			squares[row1*3 + col1][i] = 0;			
		}
	}
	return false;
}

int main() {
	int k;
	scanf("%d",&k);
	for(int i = 0;i<k;i++){
		int first, second;
		char row1, row2;
		int col1, col2;
		scanf("%d %c%d %d %c%d\n", )
	}
	for(int i = 1;i<=9;i++){
		for(int j = 1;j<=9;j++){
			
		}
	}
	return 0;
}