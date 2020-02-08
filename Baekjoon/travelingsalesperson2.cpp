//baekjoon 10971
#include <iostream>
#include <algorithm>
using namespace std;

int w[11][11];

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
	
	for(int i = 0;i<n;i++){
		for(int j =0;j<n;j++){
			cin>>w[i][j];	
		}
		
	}
	int input[n];
	for(int i = 0;i<n;i++){
		input[i] = i;
	}
	int min = 10000001;
	do{
		if(w[input[n-1]][input[0]] == 0){
			continue;
		}
		int sum = w[input[n-1]][input[0]];
		for(int i = 0;i+1<n;i++){
			if(w[input[i]][input[i+1]] == 0){
				sum = 10000001;
				break;
			}
			sum += w[input[i]][input[i+1]];
		}
		
		if(min > sum){
			min = sum;
		}
		
	}while(next_permutation(input+1, n-1));
    //At the end come back to the starting point
    //1 2 3 4 == 2 3 4 1 == 3 4 1 2 == 4 1 2 3
    //So just fix 1 in the first route.
	cout<<min<<"\n";
	return 0;
}