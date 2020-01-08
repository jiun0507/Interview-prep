//baekjoon 16940
//DFS and BFS implemented using edge list(count array) and linked list(vector)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int check[100001];
vector<int> bfs;
vector<int> connection2[100001];
int submit[100001];
int subIndex;
int parent[100001];

bool BFSlist(int index){
	queue<int> q;
	q.push(index);
	check[index] = 1;
	subIndex = 1;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		bfs.push_back(top);
		// cout<<top<<" ";
		// cout<<"size is: "<<connection2[top].size()<<"\n";
		int pushed = 0;
		for(int E: connection2[top]){
			if(!check[E]){
				parent[E] = top;
				pushed +=1;
			}
		}
		// cout<<"when top "<<top<<"subIndex = "<<subIndex<<" pushed is "<<pushed<<"\n";
		for(int i = subIndex;i<subIndex + pushed;i++){
			if(parent[submit[i]] != top){
				return false;
			}
			else{
				q.push(submit[i]);
				check[submit[i]] = 1;
			}
		}
		subIndex += pushed;
		
	}
	
	return true;
}

int main() {
	cin>>n;
	for(int i =0 ;i<n-1;i++){
		int from, to;
		cin>>from>>to;
		connection2[from].push_back(to);
		connection2[to].push_back(from);
		
	}
	for(int i =0 ;i<n;i++){
		cin>>submit[i];
	}
	for(int i = 1;i<=n;i++){
		sort(connection2[i].begin(), connection2[i].end());
	}
	bool ok= false;
	if(BFSlist(1)){
		ok = true;
	}
	
	
	cout<<ok<<"\n";;
	return 0;
}