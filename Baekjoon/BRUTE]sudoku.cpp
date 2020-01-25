//baekjoon 2580

//sudoku backtracking brute force method using recursion.

#include <iostream>
#include <vector>
using namespace std;
int n;
int ans = 0;
int squares[9][10];
int check_row[9][10];//first dimension is the row num. second dimension tells if the number exists in the row.
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
	for(int i = 0;i<9;i++){
		for(int j = 0;j<9;j++){
			int temp;
			cin>>temp;
			block[i][j] = temp;
			check_row[i][temp] = 1;
			check_col[j][temp] = 1;
			squares[(i/3)*3 + j/3][temp] = 1;
			if(temp == 0){
				empty.push_back(make_pair(i,j));
			}
		}
	}
	
	bool found = go(empty[0].first,empty[0].second, 0);
	for(int i = 0;i<9;i++){
		for(int j = 0;j<9;j++){
			cout<<block[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}