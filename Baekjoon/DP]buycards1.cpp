//baekjoon 11052 이친수 카드구매하기
//최대 구매값 구하기
#include <iostream>
#include <algorithm>
using namespace std;

int memo[1001]= {0};
//recursion
int ncard(int n, int price[]){
	if(n==0){
		return 0;
	}
	if(memo[n]>0){
		return memo[n];
	}
	int maxP = 0;
	for(int i =1;i<=n;i++){
		maxP = max(maxP,ncard(n-i, price)+price[i]);
		
	}
	memo[n] = maxP;
	return memo[n];
}
//forloop
int ncard2(int n, int price[]){
	
	for(int i = 1; i<=n;i++){
		for(int j = 1;j<=i;j++){
			memo[i] = max(memo[i], memo[i-j]+price[j]);
			
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