//baekjoon onetwothree 11055
//maximum sum of increasing array of numbers.
#include <iostream>
#include <algorithm>
using namespace std;

int memo[1001];
int arr[1001];
void lisum(int n){
	memo[0] = arr[0];
	for(int i = 1;i<n;i++){
		memo[i] = arr[i];
		for(int j = 0;j<=i;j++){
			if(arr[i] > arr[j] && memo[i] <(arr[i] + memo[j])){
				memo[i] = arr[i] + memo[j];
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