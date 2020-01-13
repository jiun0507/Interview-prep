//baekjoon 14889
//스타트와 링크 축구경기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int w[20][20];
int least = 100000000;

int stats(vector<int> &team){
	int sum = 0;
	for(int i = 0; i<team.size();i++){
		for(int j = 0;j<team.size();j++){
			if(i==j) continue;
			sum += w[team[i]][team[j]];
		}
	}
	return sum;
}

void soccer(int index, vector<int> &teamx, vector<int> &teamy){
	if(index == n){
		if(teamx.size() != n/2 || teamy.size() != n/2){
			return;
		}
		int diff = stats(teamx) - stats(teamy);
		if(diff < 0) diff = -diff;
		if(least>diff) least = diff;
		return;
	}
	teamx.push_back(index);
	soccer(index + 1, teamx, teamy);
	teamx.pop_back();
	teamy.push_back(index);
	soccer(index + 1, teamx, teamy);
	teamy.pop_back();
	return;
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
	soccer(0, teamx, teamy);
	cout<<least<<"\n";
	return 0;
}