//baekjoon onetwothree 9095
//make n using one two three.number of ways
#include <iostream>
using namespace std;

int memo[13]= {0};

int ott(int n){
	if(n<0){
		return 0;
	}
	if(n==0){
		return 1;
	}
	if(memo[n]>0){
		return memo[n];
	}
	return ott(n-1)+ott(n-2)+ott(n-3);
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