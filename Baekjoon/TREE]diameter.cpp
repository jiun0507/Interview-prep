//baekjoon 1167
//find diameter of a tree using BFS twice
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<pair<int,int>> connection2[100010];
int check[100001];
int dist[100001];
void BFSlist(int index){
	memset(check, 0, sizeof(check));
	memset(dist, 0, sizeof(dist));
	queue<int> q;
	q.push(index);
	check[index] = 1;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		for(pair<int,int> E: connection2[top]){
			if(!check[E.first]){
				q.push(E.first);
				check[E.first] = 1;
				dist[E.first] = dist[top] + E.second;
			}
		}
	}
	return;
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
	
	
	BFSlist(1);
	int maxdist = 0;
	int start;
	for(int i =2;i<=n;i++){
		if(maxdist< dist[i]){
			maxdist = dist[i];	
			start = i;
		} 
	}
	// cout<<maxdist<<" "<<index<<"\n";
	BFSlist(start);
	for(int i =1;i<=n;i++){
		if(maxdist< dist[i]){
			maxdist = dist[i];	
		} 
	}
	cout<<maxdist<<"\n";
	return 0;
}