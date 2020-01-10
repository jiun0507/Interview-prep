//baekjoon 1167

//finding tree diameter using DFS in postorder
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<pair<int,int>> connection2[100010];
int check[100001];
//first = diameter, second = height
pair<int,int> DFSlist(int index){
	check[index] = 1;
	vector<int> heights;
	int ans = 0;
	for(pair<int,int> E: connection2[index]){
		if(!check[E.first]){
			auto p = DFSlist(E.first);
			if(ans < p.first) ans = p.first;
			heights.push_back(p.second + E.second);
		}
	}
	
	int height = 0;
	sort(heights.begin(), heights.end());
	reverse(heights.begin(), heights.end());
	if(heights.size()>=1){
		height = heights[0];
		if(ans<height) ans = height;
	}
	if(heights.size()>=2){
		if(ans<heights[0] + heights[1]){
			ans = heights[0] + heights[1];
		}
	}
	return make_pair(ans, height);
}

int main() {
	int n;
	cin>>n;
	for(int i =1 ;i<=n;i++){
		int from;
		cin>>from;
		while(true){
			int to, wt;
			cin>>to;
			if(to == -1) break;
			cin>>wt;
			connection2[from].push_back(make_pair(to, wt));
		}
	}
	
	for(int i = 1;i<=n;i++){
		sort(connection2[i].begin(), connection2[i].end());
	}
	
	
	pair<int,int> ans = DFSlist(1);
	cout<<ans.first<<"\n";
	return 0;
}