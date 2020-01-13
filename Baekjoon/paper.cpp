//baekjoon 14391
//paper cut
#include <iostream>
using namespace std;

int n,m;
int board[4][4];
//gets numbers from the papers. bitmask has the side or ups of each number
//on the board. -> translates that into numbers
int getnumber(int bitmask){
	int sum = 0;
	for(int i = 0;i<n;i++){
		int right = 0;
		for(int j = 0;j<m;j++){
			if((bitmask & ( 1<< (i*m +j) ))==0){
				right *=10;
				right += board[i][j];
			}
			else{
				sum += right;
				right = 0;
			}
			
		}
		sum += right;
	}
	for(int i = 0;i<m;i++){
		int down = 0;
		for(int j = 0;j<n;j++){
			if((bitmask&(1<<(i + j*m)))>0){
				down *=10;
				down += board[j][i];
			}
			else{
				sum += down;
				down = 0;
			}
		}
		sum += down;
	}
	return sum;
}

//bitmask
int go(){
	int maximum = 0;
	for(int i =0;i<(1<<(n*m));i++){
		int sum = getnumber(i);
		if(maximum<sum) maximum = sum;
	}
	return maximum;
}

int main() {
	cin>>n>>m;
	
	/*for(int i = 0;i<n;i++){
		int buf;
		cin>>buf;
		for(int j = m-1;j>=0;j--){
			board[i][j] = buf%10;
			buf /=10;
		}
	}
    cout<<go()<<"\n";
    */
   for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			scanf("%1d", &board[i][j]);
		}
	}
	
	int ans = go();
	printf("%d", ans);
	
	return 0;
}