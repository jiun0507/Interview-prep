//baekjoon 1260

//DFS and BFS implemented using edge list(count array) and linked list(vector)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int n,m;
bool connection1[1001][1001];
vector<int> connection2[1001];
vector<pair<int,int>> connection3;
int check[1001];
int cnt[1001];
void DFSlist(int index){
	check[index] = 1;
	cout<<index<<" ";
	for(int E:connection2[index]){
		if(!check[E]){
			DFSlist(E);
		}
	}
	return;
}

void DFSarray(int index){
	check[index] = 1;
	cout<<index<<" ";
	for(int i = cnt[index-1];i< cnt[index];i++){
		int next = connection3[i].second;
		if(!check[next]){
			DFSarray(next);
		}
	}
	return;
}

void BFSlist(int index){
	queue<int> q;
	q.push(index);
	check[index] = 1;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		cout<<top<<" ";
		for(int E: connection2[top]){
			if(!check[E]){
				q.push(E);
				check[E] = 1;
			}
		}
	}
	return;
}
void BFSarray(int index){
	queue<int> q;

	q.push(index);
	check[index] = 1;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		cout<<top<<" ";
		for(int i = cnt[top-1];i<cnt[top];i++){
			int next = connection3[i].second;
			if(!check[next]){
				q.push(next);
				check[next] = 1;
			}
		}
	}
	return;
}
//
int main() {
	int start;
	cin>>n>>m>>start;
	for(int i =0 ;i<m;i++){
		int from, to;
		cin>>from>>to;
		connection3.push_back({from, to});
		connection3.push_back({to, from});
		connection2[from].push_back(to);
		connection2[to].push_back(from);
		connection1[from][to] = connection1[to][from] = 1;
	}
	
	for(int i = 0;i<n;i++){
		sort(connection2[i].begin(), connection2[i].end());
	}
	m*=2;//pushed twice for one edge in connection3 because it is bidirection
	sort(connection3.begin(), connection3.end());
	for(int i = 0;i<m;i++){
		cnt[connection3[i].first] += 1;
	}
	for(int i = 1;i<=n;i++){
		cnt[i] += cnt[i-1];
	}

	DFSarray(start);
	cout<<"\n";
	memset(check, 0, sizeof(check));
	BFSarray(start);
	return 0;
}