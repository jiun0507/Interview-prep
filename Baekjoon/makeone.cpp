//Baekjoon 1463
#include <iostream>
#include <algorithm>
using namespace std;

int memo[1000001]= {0};

int makeone(int n){
	if(memo[n]>0){
		return memo[n];
	}
	if(n==1){
		return 0;
	}
	int mini = 200000000;
	if(n%3 == 0){
		mini = min(mini, makeone(n/3)+1);
	}
	if(n%2 == 0){
		mini = min(mini, makeone(n/2)+1);
	}
	mini = min(mini, makeone(n-1)+1);
	memo[n] = mini;
	return memo[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	cout<<makeone(n)<<"\n";
	return 0;

}