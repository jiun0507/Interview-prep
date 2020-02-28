//baekjoon 5014
//스타트 링크 
include <iostream>
#include <bits/stdc++.h>

using namespace std;
int f, s, g, u, d;
int dist[1000001];

int BFSelevator(int level){
	queue<int> list;
	dist[level] = 0;
	list.push(level);
    while(!list.empty()){
        int p = list.front();
        if(p == g) return dist[p];
        list.pop();
        int cur = dist[p];
        if(p-d>=1 && dist[p-d]==-1){
            dist[p-d] = cur+1;
            list.push(p-d);
        }
        if(p+u<=f&& dist[p+u]==-1){
            dist[p+u] = cur+1;
            list.push(p+u);
        }
    }
	return -1;
}

int main() {
	cin>>f>>s>>g>>u>>d;
	memset(dist, -1, sizeof(dist));
	int ans = BFSelevator(s);
	if(ans == -1){
	    cout<<"use the stairs\n";
	    return 0;
	}
	cout<<ans<<"\n";

	return 0;
}
