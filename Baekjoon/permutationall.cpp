//baekjoon 10974
#include <iostream>
#include <algorithm>
using namespace std;

bool next_permutation(int *a, int n){
	int i = n-1;
	while(i>0 && a[i]<=a[i-1]) i--;
	if(i<=0){
		return false;
	}
	int j = n-1;
	while(a[i-1]>=a[j]){
		j--;
	}
	swap(a[i-1],a[j]);
	j = n-1;
	while(j>i){
		swap(a[j], a[i]);
		i+=1; 
		j-=1;
	}
	return true;
}
int main() {
	int n;
	cin>>n;
	int input[n];
	for(int i = 1;i<=n;i++){
		input[i-1] = i;
	}
	do{
		for(int i = 0;i<n;i++){
			cout<<input[i]<<" ";
		}
		cout<<"\n";
	}while(next_permutation(input, n));
	
	return 0;
}