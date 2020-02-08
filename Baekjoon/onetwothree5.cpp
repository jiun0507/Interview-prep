//baekjoon 15990 1,2,3 add 5
//number of possible ways of adding up to n using 1,2,3 without using twice in a row
//keep an eye on the int, long long overflow and when to use mod
//My error: using mod before adding to the sum. Use % after adding some thing
//to the sum!
#include <iostream>
using namespace std;

long long memo[100001][4]= {0};

int ott(int n, int j){
	if(n-j<0){
		return 0;
	}
	if(n==j){
		return 1;
	}
	if(memo[n][j]>0){
		return memo[n][j];
	}
	int sum = 0;
	for(int i = 1; i<=3;i++){
		if(j!= i){
			sum += ott(n-j, i);
			sum %= 1000000009;
		}
	}
	memo[n][j] = sum%1000000009;
	return memo[n][j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	while(n--){
		int input;
		cin>>input;
		
		cout<<ott(input,0)<<"\n";
	}
	
	return 0;

}