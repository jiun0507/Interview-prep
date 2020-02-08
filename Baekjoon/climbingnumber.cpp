//baekjoon onetwothree 11057
//number of 오르막수
#include <iostream>
#include <algorithm>
using namespace std;

long long increase[1001][10]= {0};
//if we paint nth house with i color. 
//the least money spent is price[n][i] = color[i] + min(price[n-1][i-1],price[n-1][i+1]);


void increasing(int n){
	for(int j = 0;j<=9;j++){
		increase[0][j] = 1;
	}
	for(int i = 1;i<n;i++){
		for(int j = 0;j<=9;j++){
			for(int k = 0;k<=j;k++){
				increase[i][j] += increase[i-1][k];
				increase[i][j] %= 10007;
			}
		}
	}
	return ;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	increasing(n);
	int sum = 0;
	for(int i = 0;i<=9;i++){
		sum += increase[n-1][i];
		sum %= 10007;
	}
	cout<<sum<<"\n";
	
	
	return 0;

}