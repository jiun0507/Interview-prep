//baekjoon 4574
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n = 9;
int ans = 0;
int pairs[10][10];
int squares[9][10];
int check_row[9][10];
int check_col[9][10];
int block[9][9];
int dy[2] = {0, 1};
int dx[2] = {1, 0};
vector<pair<int,int>> empty; 

bool check_range(int y, int x){
	if(y<0 || y==n || x<0 || x== n) return false;
	return true;
}
void check(int y, int x, int number, int value){
	check_row[y][number]= value;
	check_col[x][number]= value;
	squares[(y/3)*3 +x/3][number] = value;
}

bool can(int y, int x, int number){
	return check_row[y][number]==0 && check_col[x][number]==0 && squares[(y/3)*3 +x/3][number] == 0;
}
bool go(int place){
	if(place == 81){
		return true;
	}
	int y = place/9;
	int x = place%9;
	if(block[y][x] !=0){
		return go(place +1);
	}
	else{
		for(int i = 0; i<2;i++){
			int newy = y+dy[i];
			int newx = x+dx[i];
			if(!check_range(newy, newx)) continue;
			if(block[newy][newx] != 0){
				continue;
			}
			for(int j = 1;j<=9;j++){
				for(int k = 1;k<=9;k++){
					if(pairs[j][k] == 1 || j ==k) continue;
					if(can(y, x, j) && can(newy, newx, k)){
						check(y, x, j, 1);
						check(newy, newx, k, 1);
						block[y][x] = j; block[newy][newx] = k;
						pairs[j][k] = pairs[k][j] = 1;
						if(go(place + 1)){
							return true;
						}
						check(y, x, j, 0);
						check(newy, newx, k, 0);
						pairs[j][k] = pairs[k][j] = 0;
						block[y][x] = 0; block[newy][newx] = 0;
					}
				}
			}
			
		}
	}
	return false;
}

int main() {
	int tc=1;
	while(true){
		memset(pairs,0,sizeof(pairs));
		memset(squares,0,sizeof(squares));
		memset(check_row,0,sizeof(check_row));
		memset(check_col,0,sizeof(check_col));
		memset(block,0,sizeof(block));
		int k;
		scanf("%d\n",&k);
		if(k == 0) break;
		printf("Puzzle %d\n", tc);
		for(int i = 0;i<k;i++){
			int first, second;
			char row1, row2;
			int col1, col2;
			scanf("%d %c%d %d %c%d\n", &first, &row1, &col1, &second, &row2, &col2);
			int y1 = row1- 'A';
			int x1 = col1 - 1;
			int y2 = row2 -'A';
			int x2 = col2 - 1;
			block[y1][x1] = first;
			block[y2][x2] = second;
			pairs[first][second] = 1;
			pairs[second][first] = 1;
			check(y1, x1, first, 1);
			check(y2, x2, second, 1);
		}
		for(int i = 1;i<=9;i++){
			char row;
			int col;
			scanf("%c%d ",&row, &col);
			block[row-'A'][col-1] = i;
			check(row -'A', col-1, i, 1);
		}
		go(0);
		for(int i = 0;i<9;i++){
			for(int j = 0;j<9;j++){
				cout<<block[i][j];
			}
			cout<<"\n";
		}
		tc++;
	}	
	return 0;
}