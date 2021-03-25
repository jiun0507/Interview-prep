// 2056 작업
// baekjoon

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int dist[10001];
bool check[10001];
int indegrees[10001];
vector<pair<int,int>> edges[10001];
vector<pair<int,int>> reverse_edge[10001];

int main()
{
    
    memset(dist, -1, sizeof(dist));
    memset(indegrees, 0, sizeof(indegrees));
    int n, m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a, b, cost;
        cin>>a>>b>>cost;
        edges[a].push_back(make_pair(b, cost));
        reverse_edge[b].push_back(make_pair(a, cost));
        indegrees[b] += 1;
    }
    int from, to;
    cin>>from>>to;
    dist[from] = 0;
    paths[from] = 0LL;
    queue<int> q;
    q.push(from);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        check[cur] = true;
        for(auto next: edges[cur]){
            if(next.second + dist[cur]>=dist[next.first]){
                dist[next.first] = next.second + dist[cur];
            }
            indegrees[next.first]--;
            if(indegrees[next.first] == 0){
                q.push(next.first);
            }
        }
    }
    memset(check, false, sizeof(check));
    q.push(to);
    int total_paths = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto next:reverse_edge[cur]){
            if(dist[next.first]==dist[cur]-next.second){
                total_paths +=1;
                if(!check[next.first]){
                    q.push(next.first);
                    check[next.first] = true;
                }
            }
        }
    }
    cout<<dist[to]<<"\n"<<total_paths<<"\n";
    return 0;
}
