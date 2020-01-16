//baekjoon onetwothree 11722
//find length of longest decreasing subarray
#include <iostream>
#include <algorithm>
using namespace std;

int memo[1001];
int arr[1001];
void lisum(int n){
	memo[0] = 1;
	for(int i = 1;i<n;i++){
		memo[i] = 1;
		for(int j = 0;j<i;j++){
			if(arr[i] < arr[j] && memo[i] <memo[j]+ 1){
				memo[i] = memo[j] + 1;
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
		cin>>arr[i];
	}
	lisum(n);
	int max =0;
	for(int i = 0;i<n;i++){
		if(max< memo[i]){
			max = memo[i];
		}
	}
	cout<<max<<" ";
	return 0;

}