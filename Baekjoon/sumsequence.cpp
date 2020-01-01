//baekjoon 1912
//연속합 문제 dp
#include <iostream>

using namespace std;

int sum[100001];
int arr[100001];

void lis(int n){
	for(int i = 1;i<n;i++){
		if(sum[i-1]>0) sum[i]+=sum[i-1];
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		sum[i] = arr[i];
	}
	lis(n);
	int max = -2100000000;
	for(int i = 0;i<n;i++){
		if(max<sum[i]){
			max = sum[i];
		}
	}
	
	cout<<max<<endl;
    return 0;

}