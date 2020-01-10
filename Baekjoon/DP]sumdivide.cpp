//baekjoon 2225
//합분해 문제->다른 dp보다 살짝 어려운 문제임

#include <iostream>

using namespace std;

int memo[201][201];

int memo2[201];


void sumdivide(int n, int k){
	memo[0][0]=1;
	for(int i = 1; i<=k;i++){
		for(int j = 0;j<=n;j++){
			for(int k = 0; k<=j;k++){
				memo[i][j] += memo[i-1][j-k];
				memo[i][j] %= 1000000000;
			}
		}
	}
}
//simplified version
//kn^2 -> kn // Use only 일차원 배열 to implement dp
void sumdivide2(int n, int k){
	memo2[0]=1;
	for(int i = 1; i<=k;i++){
		for(int j = 0;j<=n;j++){
			memo2[j] = memo[j];
			if(j-1>=0){
				memo2[j] += memo[j-1];
			}
			memo2[j] %= 1000000000;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin>>n>>k;
	sumdivide(n,k);
	cout<<memo[k][n]<<"\n";
    return 0;

}