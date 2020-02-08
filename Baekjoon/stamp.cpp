//baekjoon onetwothree 9465
//2xn stamp. maximum price.
#include <iostream>
#include <algorithm>
using namespace std;

int memo[100001][3]= {0};
int stamp[100001][2];
//if we paint nth house with i color. 
//the least money spent is price[n][i] = color[i] + min(price[n-1][i-1],price[n-1][i+1]);


void stamping(int n){
	for(int j = 1;j<3;j++){
		memo[0][j] = stamp[0][j-1];
	}
	for(int i = 1;i<n;i++){
		memo[i][1] = stamp[i][0] + max(memo[i-1][0], memo[i-1][2]);
		memo[i][2] = stamp[i][1] + max(memo[i-1][0], memo[i-1][1]);
		int zero = max(memo[i-1][0], memo[i-1][1]);
		zero = max(zero, memo[i-1][2]);
		memo[i][0] = zero;
	}
	return ;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int j = 0;j<2;j++){
			for(int i = 0;i<n;i++){
				cin>>stamp[i][j];
			}
		}
		stamping(n);
		int max = 0;
		for(int i = 0;i<3;i++){
			if(max<memo[n-1][i]){
				max = memo[n-1][i];
			}
		}
		cout<<max<<"\n";
	}
	
	
	return 0;

}