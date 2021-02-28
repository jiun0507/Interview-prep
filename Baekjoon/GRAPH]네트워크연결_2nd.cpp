// 1922 네트워크 연결
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

struct edge
{
    int dist;
    int dest;
    edge(int dist_, int dest_) : dist(dist_), dest(dest_) {}
};
struct cmp
{
    bool operator()(edge a, edge b)
    {
        return a.dist > b.dist;
    }
};

int check[1001];
vector<edge> adj[1001];
int n, m;

int main()
{
    cin >> n >> m;
    memset(check, -1, sizeof(check));

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(edge(c, b));
        adj[b].push_back(edge(c, a));
    }
    priority_queue<edge, vector<edge>, cmp> pq;
    for (auto start : adj[1])
    {
        pq.push(edge(start.dist, start.dest));
    }
    check[1] = 1;
    int ans = 0;
    while (!pq.empty())
    {
        auto next = pq.top();
        pq.pop();
        if (check[next.dest] != -1)
            continue;
        ans += next.dist;
        pq.push(edge(next.dist, next.dest));
        check[next.dest] = 1;
        for (auto eg : adj[next.dest])
        {
            pq.push(edge(eg.dist, eg.dest));
        }
    }
    cout << ans << "\n";

    return 0;
}
