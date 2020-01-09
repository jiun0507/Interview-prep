//baekjoon 13549
//using two queus. 가중치가 두개
//deque 사용하지 않은 솔루션

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int n,k;
int check[100010];
int dist[100010];//100001이여도 상관 없음

void BFSlist(int index){
	queue<int> q;
	q.push(index);
	check[index] = 1;
	dist[index] = 0;
	queue<int> next_queue;
	while(!q.empty()){
		int x = q.front();
		q.pop();

        //x*2가 먼저와야 한다. x+1 x-1이 check해버리기 전에 먼저 check될 필요가 있음.
		if(x*2<=100000){
			if(!check[x*2]){
				q.push(x*2);
				check[x*2] = 1;
				dist[x*2] = dist[x];	
			}
		}
		if(x-1>=0){
			if(!check[x-1]){
				next_queue.push(x-1);
				check[x-1] = 1;
				dist[x-1] = dist[x] +1;
			}
		}
		if(x+1<=100000){
			if(!check[x+1]){
				next_queue.push(x+1);
				check[x+1] = 1;
				dist[x+1] = dist[x]+1;
			}
		}
		if(q.empty()){
			q = next_queue;
			next_queue = queue<int>();
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