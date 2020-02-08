//baekjoon 14501
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int t[15];
int p[15];


int free(int index, int bonus, int n){
	
	if(index == n){
		return bonus;
	}
	if(index > n){
		return 0;
	}
	int maximum = max(free(index + t[index], bonus + p[index], n), free(index + 1 , bonus, n));
	return maximum;
}

int main() {
	int n;
	cin>>n;
	
	for(int i = 0;i<n;i++){
		cin>>t[i]>>p[i];
	}
	int ans = free(0, 0, n);
	cout<<ans<<"\n";
	return 0;
}