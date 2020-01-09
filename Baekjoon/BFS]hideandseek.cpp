//baekjoon 1697

//from n go to k
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int n,k;
int check[100010];
int cnt[100010];

int BFSlist(int index){
	queue<int> q;
	q.push(index);
	check[index] = 1;
	int distance = 0;
	cnt[index] = distance;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		if(top == k){
			return cnt[top];
		}
		if(top>0 && !check[top-1]){
			q.push(top-1);
			check[top-1] = 1;
			cnt[top-1] = cnt[top] +1;
		}
		if(top*2<=100000 &&!check[top*2]){
			q.push(top*2);
			check[top*2] = 1;
			cnt[top*2] = cnt[top]+1;
		}
		if(top+1<=100000 && !check[top+1]){
			q.push(top+1);
			check[top+1] = 1;
			cnt[top+1] = cnt[top] +1;
		}
	}
	return -1;
}
int main() {
	cin>>n>>k;
	cout<<BFSlist(n)<<"\n";

	return 0;
}