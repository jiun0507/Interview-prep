// 1197 최소수패닝 트리
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

struct edge
{
    int dist;
    int from, to;
    edge(int dist_, int from_, int to_) : dist(dist_), from(from_), to(to_) {}
};
bool operator<(edge a, edge b)
{
    return a.dist > b.dist;
}
int check[10001];
vector<edge> adj[10001];
int parent[10001];
int v, e;

int rep(int a)
{
    if (a == parent[a])
    {
        return a;
    }
    return parent[a] = rep(parent[a]);
}

int main()
{
    memset(check, -1, sizeof(check));
    cin >> v >> e;
    for (int i = 1; i <= v; i++)
    {
        parent[i] = i;
    }
    priority_queue<edge, vector<edge>> pq;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push(edge(c, a, b));
    }
    int ans = 0;
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int from = rep(cur.from);
        int to = rep(cur.to);
        if (from != to)
        {
            parent[from] = to;
            ans += cur.dist;
        }
    }
    cout << ans << "\n";

    return 0;
}
