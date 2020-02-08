//baekjoon  1170
//bruteforce remote controller question
#include <iostream>
#include <algorithm>
using namespace std;

int broken[10];

int possible(int c){
	if(c==0){
		if(!broken[0]){
			return 1;
		}
		else{
			return 0;
		}
	}
	int length = 0;
	while(c>0){
		if(broken[c%10]){
			return 0;
		}
		length+=1;
		c /= 10;
	}
	return length;
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int channel;
	cin>>channel;
	int n;
	cin>>n;
	for(int i = 0; i<n;i++){
		int b;
		cin>>b;
		broken[b] = 1;
	}
	int ans = channel-100;
	if(ans <0){
		ans = -ans;
	}
	for(int i = 0; i<=1000000;i++){
		int length = possible(i);
		if(length ==0){
			continue;
		}
		int move = channel-i;
		if(move < 0) move = -move;
		ans = min(ans, length+move);
	}
	cout<<ans<<"\n";
	return 0;

}