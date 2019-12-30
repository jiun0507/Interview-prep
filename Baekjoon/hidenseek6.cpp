#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
	if(b==0){
		return a;	
	}
	return gcd(b,a%b);
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x;
	cin>>n>>x;
	int input[1000001];
	for(int i =0 ;i<n;i++){
		cin>>input[i];
	}
	int b = max(x-input[0],input[0]-x);
	for(int i = 1;i<n;i++){
		int a = max(input[i]-input[i-1], input[i-1]-input[i]);
		b = gcd(a, b);
	}
	cout<<b;
	
	return 0;
}