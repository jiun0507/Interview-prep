//baekjoon 16947
//DFS to find the circle. BFS to find the distance between subways
//DFS and BFS implemented using edge list(count array) and linked list(vector)

//continue; takes a long time -> try not to use it.
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int check[3001];
int dist[3001];
vector<int> connection2[3001];


int DFSlist(int index, int prev){
	if(check[index]){
		return index;
	}
	check[index] = 1;
	for(int next: connection2[index]){
		if(next == prev) continue;
		int start = DFSlist(next, index);
		if(start>0){
			if(index == start){
				check[index] = 2;
				return -2;
			}
			else{
				check[index] = 2;
				return start;
			}
		}
		else if(start == -2){
			check[index] = -2;
			return -2;
		}
	}
	return -1;
}



int main() {
	cin>>n;
	for(int i =0 ;i<n;i++){
		int from, to;
		cin>>from>>to;
		connection2[from].push_back(to);
		connection2[to].push_back(from);
	}
	
	for(int i = 1;i<=n;i++){
		sort(connection2[i].begin(), connection2[i].end());
	}

	DFSlist(1,-1);
	queue<int> q;

	for(int i = 1;i<=n;i++){
		if(check[i] == 2){
			q.push(i);
			dist[i] = 0;
		}
		else{
			dist[i] = -1;
		}
	}
	while(!q.empty()){
		int top = q.front();
		q.pop();
		for(int E: connection2[top]){
			if(dist[E] ==-1){
				q.push(E);
				dist[E] = dist[top] + 1;
			}
		}
	}
	for(int i = 1;i<=n;i++){
		cout<<dist[i]<<" ";
	}
	cout<<"\n";
	return 0;
}