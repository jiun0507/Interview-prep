//baekjoon9613
//gcd 합
#include <iostream>

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
	int t;
	cin>>t;
	while(t--){
		int input[101];
		int n;
		cin>>n;
		for(int i =0 ; i<n;i++){
			cin>>input[i];
		}
		long long sum = 0; 
        //there will be at most 5000 combinations out of 100 numbers which might have
        //at most 10000000 of gcd -> so need long long
		for(int i =0 ; i+1<n;i++){
			for(int j =i+1 ; j<n;j++){
				sum += gcd(input[i],input[j]);
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}