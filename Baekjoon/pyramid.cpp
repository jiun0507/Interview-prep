//baekjoon onetwothree 1932
//pyramids
#include <iostream>
#include <algorithm>
using namespace std;

int memo[501][501]= {0};
int arr[501][501];
void pyramid(int n){
	memo[0][0] = arr[0][0];
	for(int i = 1;i<n;i++){
		for(int j = 0;j<=i;j++){
			if(j == 0){
				memo[i][j] = arr[i][j] + memo[i-1][j];
			}
			else if(j == i){
				memo[i][j] = arr[i][j] + memo[i-1][j-1];
			}
			else{
				memo[i][j] = arr[i][j]+ max(memo[i-1][j],memo[i-1][j-1]);
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
	for(int i = 0; i <n; i++){
		for(int j = 0;j<=i;j++){
			cin>>arr[i][j];
		}
	}
	pyramid(n);
	int max =0;
	for(int i = 0;i<n;i++){
		if(max< memo[n-1][i]){
			max = memo[n-1][i];
		}
	}
	cout<<max<<" ";
	return 0;

}