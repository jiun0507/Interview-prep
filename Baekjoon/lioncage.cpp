//baekjoon onetwothree 1309
//number of putting lions in 2xn cage without putting them beside each other
#include <iostream>
#include <algorithm>
using namespace std;

long long lion[100001][4]= {0};
//if we paint nth house with i color. 
//the least money spent is price[n][i] = color[i] + min(price[n-1][i-1],price[n-1][i+1]);


void cage(int n){
	for(int j = 0;j<3;j++){
		lion[0][j] = 1;
	}
	for(int i = 1;i<n;i++){
		for(int j = 0;j<3;j++){
			lion[i][j] += lion[i-1][0];
			lion[i][j] %= 9901;
			if(j == 1 || j ==0){
				lion[i][j] += lion[i-1][2];
				lion[i][j] %= 9901;
			} if(j == 2 || j == 0){
				lion[i][j] += lion[i-1][1];
				lion[i][j] %= 9901;
			} 
			lion[i][j] %= 9901;
		}
	}
	return ;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	cage(n);
	int sum = 0;
	for(int i = 0;i<3;i++){
		sum += lion[n-1][i];
		sum %= 9901;
	}
	cout<<sum<<"\n";
	
	
	return 0;

}