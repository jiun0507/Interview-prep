//1922 네트워크 연결
// baekjoon
//연결리스트
#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

vector<pair<int,int>> adj[1001];
int check[1001];
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    cin>>m;
    memset(check, -1, sizeof(check));
    for(int i = 0;i<m;i++){
        int a, b, dist;
        cin>>a>>b>>dist;
        adj[a].push_back(make_pair(dist, b));
        adj[b].push_back(make_pair(dist, a));
    }
    priority_queue<pair<int,int>> pq;

    check[1] = 1;
    for(auto &line:adj[1]){
        pq.push(make_pair(-line.first, line.second));
    }
    int ans = 0;
    while(!pq.empty()){
        pair<int,int> cur = pq.top();
        pq.pop();
        int now = cur.second;
        if(check[now]!=-1){
            continue;
        }
        ans -= cur.first;
        check[now] = 1;
        for(auto &line:adj[now]){
            pq.push(make_pair(-line.first, line.second));
        }
    }
    cout<<ans<<"\n";
    return 0;
}
