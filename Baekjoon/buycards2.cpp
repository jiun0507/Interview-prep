//baekjoon buycards2
//minimum price 16194

#include <iostream>
#include <algorithm>
using namespace std;

int memo[1001]= {0};
int ncard(int n, int price[]){
	
	
	for(int i = 1; i<=n;i++){
		memo[i] = -1;//There cannot be -1 so use -1 as a sign that memo[i] is not input yet
		for(int j = 1;j<=i;j++){
			if(memo[i]==-1||memo[i]>memo[i-j]+price[j]){
				memo[i] =  memo[i-j]+price[j];
			}
		}
	}
	return memo[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	int price[n+1];
	for(int i =1 ;i<=n;i++){
		cin>>price[i];
		
	}
	
	cout<<ncard(n, price)<<"\n";
	
	
	return 0;

}