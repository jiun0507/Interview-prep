//baekjoon 10819
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
	sort(input,input+n);
	int max = 0;
	do{
		int sum = 0;
		for(int i = 0;i+1<n;i++){
			int dif = input[i+1]-input[i];
			if(dif<0){
				dif = -dif;
			}
			sum += dif;
		}
		if(max<sum){
			max = sum;
		}
	
	}while(next_permutation(input, n));
	
	cout<<max;
	
	return 0;
}