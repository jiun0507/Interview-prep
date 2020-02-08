//baekjoon 3085
//brute force 
//50 x 50 x 50 x 50
#include <iostream>
#include <algorithm>
using namespace std;

char board[51][51];

int longest(int n){
	int max = 0;
	for(int i =0;i<n;i++){
		int length = 1;
		for(int j =1;j<n;j++){
			if(board[i][j] == board[i][j-1]){
				if(max<++length){
					max = length;
				}
			}
			else{
				length =1;
			}
		}
	}
	for(int j =0;j<n;j++){
		int length = 1;
		for(int i =1;i<n;i++){
			if(board[i][j] == board[i-1][j]){
				if(max<++length){
					max = length;
				}
			}
			else{
				length =1;
			}
		}
	}
	return max;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	
	for(int i =0;i<n;i++){
		for(int j =0;j<n;j++){
			cin>>board[i][j];
		}
	}
	int max = 0;
	for(int i =0;i<n;i++){
		for(int j =0;j<n;j++){
			if(i+1<n){
				char swap = board[i][j];
				board[i][j] = board[i+1][j];
				board[i+1][j] = swap;
				int length = longest(n);
				if(length>max){
					max = length;
				}
				board[i+1][j] = board[i][j];
				board[i][j] = swap;
			}
			if(j+1<n){
				char swap = board[i][j];
				board[i][j] = board[i][j+1];
				board[i][j+1] = swap;
				int length = longest(n);
				if(length>max){
					max = length;
				}
				board[i][j+1] = board[i][j];
				board[i][j] = swap;
			}
		}
	}
	cout<<max<<endl;

	return 0;

}