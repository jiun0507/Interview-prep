//baekjoon 13398
//연속합 문제2 dp 하나뺄수 있음.
#include <iostream>
#include <algorithm>
using namespace std;

int sum1[100001];
int sum2[100001];
int arr[100001];

void lis(int n){
	for(int i = 1;i<n;i++){
		if(sum1[i-1]>0) sum1[i]+=sum1[i-1];
	}
	return;
}
void dis(int n){
	for(int i = n-2;i>=0;i--){
		if(sum2[i+1]>0) sum2[i]+=sum2[i+1];
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
		sum1[i] = arr[i];
		sum2[i] = arr[i];
	}
	lis(n);
	dis(n);
	int max = -2100000000;
	for(int i = 0;i<n;i++){
		if(max<sum1[i]){
			max = sum1[i];
		}
	}
	for(int i = 1;i+1<n;i++){
		if(max<sum1[i-1]+sum2[i+1]){
			max = sum1[i-1]+sum2[i+1];
		}
	}

	cout<<max<<endl;
    return 0;

}