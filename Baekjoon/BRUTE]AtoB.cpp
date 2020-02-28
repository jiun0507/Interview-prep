//baekjoon 16953
//A to B
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long long m;
long long calc(long long n){
	if(n==m){
		return 1;
	}
	if(n>m) return 100;
	long long ans = min(1+calc(2*n), 1+calc(10*n+1));
	return ans;
}

int main() {
	long long n;
	cin>>n>>m;
	
	long long ans = calc(n);
	if(ans>=100) cout<<"-1\n";
	else{
		cout<<ans<<"\n";
	}
	return 0;
}