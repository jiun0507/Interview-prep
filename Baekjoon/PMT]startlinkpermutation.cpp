//baekjoon 14889

//startlink problem solved using permutation
//time complexity: 20! / 10!x10! = 100000~

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int w[20][20];
int least = 100000000;

int stats(vector<int> &team){
	int len = team.size();
	int sum = 0;
	for(int i = 0; i<len;i++){
		if(team[i] != 0) continue;
		for(int j = 0;j<len;j++){
			if(team[j] == 0 && i!=j) sum += w[i][j];
			
		}
	}
	for(int i = 0; i<len;i++){
		if(team[i] != 1) continue;
		for(int j = 0;j<len;j++){
			if(team[j] == 1 && i!=j) sum -= w[i][j];
		}
	}
	return sum;
}


int main() {
	cin>>n;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cin>>w[i][j];
		}
	}
	vector<int> teamx;
	vector<int> teamy;
	vector<int> members;
	for(int i = 0;i<n/2;i++){
		members.push_back(0);
	}
	for(int i = n/2;i<n;i++){
		members.push_back(1);
	}
	do{
		int temp = stats(members);
		if(temp < 0) temp = -temp;
		if(temp < least) least = temp;
	}while(next_permutation(members.begin(), members.end()));
	
	cout<<least<<"\n";
	
	return 0;
}