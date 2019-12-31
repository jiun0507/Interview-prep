#baekjoon 17103 goldbach partition question
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int ans[500000];
	int plength = 0;
	int input[101];
	int max = 0;
	int n;
	cin>>n;
	for(int i =0;i<n;i++){
		int x;
		cin>>x;
		input[i] = x;
		if(max<x){
			max = x;
		}
	}
	int check[max+1] = {0};
	for(int i=2;i<=max;i++){
		if(check[i]==0){
			ans[plength++]=i;
		}
		for(int j = i+i;j<=max;j+=i){
			check[j] = 1;
		}
	}
	for(int l =0;l<n;l++){
		int inp = input[l];
		int sum = 0;
		for(int i=0; i<plength;i++){
			
			int a = ans[i];
			if(a>inp/2){
				break;
			}
			else if(check[inp-a]==0){
				sum +=1;
				//cout<<"works"<<a<<" "<<inp-a<<"\n";
			}
			
		}
		cout<<sum<<"\n";
	}
	return 0;

}