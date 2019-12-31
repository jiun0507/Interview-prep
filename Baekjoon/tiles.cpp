//baekjoon tiles 11726 2xn tile
#include <iostream>
using namespace std;

int memo[1000001]= {0};

int tiles(int n){
	if(n<0){
		return 0;
	}
	if(n<=1){
		return 1;
	}
	if(memo[n]>0){
		return memo[n];
	}
	memo[n] = tiles(n-1)%10007 + tiles(n-2)%10007 ;
	return memo[n]%10007;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	cout<<tiles(n)<<"\n";
	return 0;

}