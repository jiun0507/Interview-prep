// 1162 도로포장
// baekjoon

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;


long long dist[10001][21];
bool check[10001][21];
const long long inf = 1000000000LL*50000LL;

struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {
    }
};
vector<Edge> edges[10001];

struct Node
{
    long long dist;
    int cur;
    int skipped;
    Node(int dist_, int cur_, int skipped_) : dist(dist_), cur(cur_), skipped(skipped_){}
};
struct cmp
{
    bool operator()(Node a, Node b)
    {
        return a.dist > b.dist;
    }
};

int main()
{
    memset(check, false, sizeof(check));
    fill(&dist[0][0], &dist[10000][20]+1, inf);
    int n, m, k;
    cin>>n>>m>>k;
    for(int i = 0;i<m;i++){
        int a, b;
        long long cost;
        cin>>a>>b>>cost;
        edges[a].push_back(Edge(b, cost));
        edges[b].push_back(Edge(a, cost));
    }
    dist[1][0] = 0;
    priority_queue<Node, vector<Node>, cmp> q; 
    q.push(Node(0, 1, 0));
    while(!q.empty()){
        auto n = q.top(); q.pop();
        int cur = n.cur;
        int skipped = n.skipped;
        int d = n.dist;
        // cout<<dist[cur][skipped]<<"\n";
        if(check[cur][skipped]) continue;
        check[cur][skipped] = true;
        for(auto next:edges[cur]){
            if(dist[next.to][skipped]>dist[cur][skipped]+next.cost){
                dist[next.to][skipped] = dist[cur][skipped]+next.cost;
                q.push(Node(dist[next.to][skipped], next.to, skipped));
            }
            if(skipped<k && dist[next.to][skipped+1]>dist[cur][skipped]){
                dist[next.to][skipped+1] = dist[cur][skipped];
                q.push(Node(dist[next.to][skipped+1], next.to, skipped+1));
            }
        }
    }
    long long mn = inf;
    for(int i = 1;i<=k;i++){
        if(check[n][i]&&dist[n][i]<mn){
            mn = dist[n][i];
        }
    }
    printf("%lld\n",mn);

    return 0;
}

