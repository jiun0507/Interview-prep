//baekjoon 13549

//using deque
#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int n,k;
int check[100010];
int dist[100010];

void BFSlist(int index){
	deque<int> q;
	q.push_front(index);
	check[index] = 1;
	dist[index] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop_front();
		if(x*2<=100000){
			if(!check[x*2]){
				q.push_front(x*2);
				check[x*2] = 1;
				dist[x*2] = dist[x];	
			}
		}
		if(x-1>=0){
			if(!check[x-1]){
				q.push_back(x-1);
				check[x-1] = 1;
				dist[x-1] = dist[x] +1;
			}
		}
		if(x+1<=100000){
			if(!check[x+1]){
				q.push_back(x+1);
				check[x+1] = 1;
				dist[x+1] = dist[x]+1;
			}
		}
	}
	return;
}
int main() {
	cin>>n>>k;
	BFSlist(n);
	cout<<dist[k]<<"\n";
	return 0;
}