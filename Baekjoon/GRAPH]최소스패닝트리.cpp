//1197 최소 스패닝 트리
// baekjoon
// Union find using arrays(find, union)
#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int parent[10001];
int n, m;

struct Edge
{
    int dist;
    int from, to;
    Edge(int _dist, int _from, int _to) : dist(_dist), from(_from), to(_to)
    {
    }
    bool operator<(const Edge &other) const
    {
        if (dist < other.dist)
            return true;
        return false;
    }
};

int find(int node)
{
    while (parent[node] != node)
    {
        node = parent[node];
    }
    return node;
}

bool unify(int u, int v)
{
    int parent_u = find(u);
    int parent_v = find(v);
    if (parent_u != parent_v)
    {
        parent[parent_v] = parent_u;
        return true;
    }

    return false;
}

vector<Edge> edges;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, dist;
        cin >> a >> b >> dist;
        edges.push_back(Edge(dist, a, b));
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (auto &child : edges)
    {
        if (unify(child.from, child.to))
        {
            ans += child.dist;
        }
    }
    cout << ans << endl;

    return 0;
}
