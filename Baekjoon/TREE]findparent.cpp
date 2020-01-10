//baekjoon 11725

//use bfs and lines and vertices to find the parents of 2 to N-1 when 1 is
//the root
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> connection2[100010];
int parent[100001];
int check[100001];

void BFSlist(int index){
	queue<int> q;
	q.push(index);
	check[index] = 1;
	parent[index] = 0;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		// cout<<top<<" ";
		for(int E: connection2[top]){
			if(!check[E]){
				q.push(E);
				check[E] = 1;
				parent[E] = top;
			}
		}
	}
	return;
}

int main() {
	int n;
	cin>>n;
		for(int i =0 ;i<n;i++){
		int from, to;
		cin>>from>>to;
		connection2[from].push_back(to);
		connection2[to].push_back(from);
	}
	
	for(int i = 0;i<n;i++){
		sort(connection2[i].begin(), connection2[i].end());
	}
	
	BFSlist(1);
	for(int i =2;i<=n;i++){
		cout<<parent[i]<<" ";
	}
	return 0;
}