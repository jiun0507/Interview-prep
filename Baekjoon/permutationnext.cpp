//baekjoon  10972
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
	for(int i = 0;i<n;i++){
		cin>>input[i];
	}
	if(!next_permutation(input, n)){
		cout<<"-1"<<"\n";
	}
	else{
		for(int i = 0;i<n;i++){
			cout<<input[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}