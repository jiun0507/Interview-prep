// 2056 작업
// baekjoon

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

long long edges[1001][1001];
int n, m;
const long long inf = 1000000000;

vector<long long> get_dist(int start){
    vector<long long> dist(n+10, inf);
    vector<bool> check(n+10, false);
    dist[start] = 0;
    for(int j = 0;j<n-1;j++){
        long long mn = inf;
        int cur = -1;
        for(int i = 1;i<=n;i++){
            if(mn>dist[i]&&!check[i]){
                mn = dist[i];
                cur = i;
            }
        }
        if(cur==-1){
            break;
        }
        check[cur] = true;
        for(int i = 1;i<=n;i++){
            if(edges[cur][i]==inf) continue;
            if(edges[cur][i] + dist[cur]<dist[i]){
                dist[i] = edges[cur][i] + dist[cur];
            }
        }
    }
    return dist;
}

int main()
{

    fill(&edges[0][0], &edges[1000][1000]+1, inf);

    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a, b;
        long long cost;
        cin>>a>>b>>cost;
        
        edges[a][b] = min(edges[a][b], cost);
        edges[b][a] = min(edges[b][a], cost);
    }
    int v1, v2;
    cin>>v1>>v2;
    vector<long long> dist_start = get_dist(1);
    vector<long long> dist_v1 = get_dist(v1);
    vector<long long> dist_v2 = get_dist(v2);
    // cout<<dist_start[v1]<<" "<<dist_v1[v2]<<" "<<dist_v2[n]<<"\n";
    // cout<<dist_start[v2]<<" "<<dist_v1[n]<<" "<<dist_v2[v1]<<"\n";
    long long v1_first = dist_start[v1]+dist_v1[v2] + dist_v2[n];
    long long v2_first = dist_start[v2]+dist_v1[n] + dist_v2[v1];

    long long ans = min(v1_first, v2_first);
    if(ans>=inf){
        cout<<-1<<"\n";
    } else{
        cout<<ans<<"\n";
    }
    return 0;
}
