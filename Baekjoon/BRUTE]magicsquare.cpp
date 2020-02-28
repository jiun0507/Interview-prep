//baekjoon 16954
//매직스퀘어로 변경하기
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int board[3][3];
int diff(vector<int> &cur){
	int ans = 0;
	for(int i = 0;i<3;i++){
		for(int j =0 ;j<3;j++){
			ans += abs(cur[i*3+j]-board[i][j]);
		}
	}
	return ans;
}
bool check(vector<int> &cur){
	
	int ans = cur[2]+cur[4]+cur[6];
	for(int i = 0;i<3;i++){
		int sumside = 0;
		int sumup = 0;
		int cross = 0;
		for(int j = 0;j<3;j++){
			sumside+=cur[i*3+j];
			sumup += cur[i+j*3];
			cross += cur[j*4];
		}
		if(sumside != ans || sumup != ans|| cross!= ans) return false;
	}
	return true;
}

int main() {
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			cin>>board[i][j];
		}
	}
	vector<int> num;
	for(int i = 1;i<=9;i++){
		num.push_back(i);
	}
	int ans = 10000;
	do{
		int temp = 10000;
		if(check(num)){
			temp = diff(num);
		}
		if(ans>temp) ans = temp;
		
	}while(next_permutation(num.begin(), num.end()));
	
	cout<<ans<<"\n";
	return 0;
}