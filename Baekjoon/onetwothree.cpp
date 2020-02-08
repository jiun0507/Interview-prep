//baekjoon onetwothree 9095
//make n using one two three.number of ways
#include <iostream>
using namespace std;

int memo[13]= {0};
//dynamic programming solution
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


//recursive solution
int go(int cnt, int sum, int goal){
	if(sum > goal){
		return 0;
	}
	if(sum == goal){
		return 1;
	}
	int ans = 0;
	ans += go(cnt +1, sum +1, goal) + go(cnt +1, sum +3, goal)+ go(cnt +1, sum +2, goal);
	return ans;
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