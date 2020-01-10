//baekjoon onetwothree 15988
//make n using one two three.number of ways with greater range of n
#include <iostream>
using namespace std;

long long memo[1000001]= {0};

long long ott(int n){
	if(n<0){
		return 0;
	}
	if(n==0){
		return 1;
	}
	if(memo[n]>0){
		return memo[n];
	}
	memo[n] = ott(n-1)+ott(n-2)+ott(n-3);
	memo[n]%= 1000000009;
	return memo[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	while(n--){
		int input;
		cin>>input;
		cout<<ott(input)<<"\n";
	}
	
	return 0;

}