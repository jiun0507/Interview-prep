//baekjoon 11053
//longest increasing sequence
//just a remainder the length[n] is not necessarily the length of longest sequence
#include <iostream>

using namespace std;

int length[1001];

int lis(int n, int arr[]){
	int longest = 0;
	for(int i = 1;i<=n;i++){
		int max = 0;
		for(int j = 0;j<i;j++){
			if(arr[i]>arr[j]&&max<length[j]){
				max = length[j];
			}
		}
		length[i] += max;
		if(longest<length[i]){
			longest = length[i];
		}
	}
	return longest;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;i<n;i++){
		length[i] = 1;
		cin>>arr[i];
	}
	
	
	cout<<lis(n,arr)<<"\n";
	return 0;

}