//15480 LCA와 쿼리
//baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

const int MAX = 100111;
int p[MAX][18];
vector<int> adj[MAX];
int tin[MAX], tout[MAX];
int depth[MAX];
int n, l;
int counter = 0;

bool upper(int u, int v)
{
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v)
{
    if (upper(u, v))
        return u;
    if (upper(v, u))
        return v;
    for (int i = l; i >= 0; i--)
    {
        if (!upper(p[u][i], v))
        {
            u = p[u][i];
        }
    }
    return p[u][0];
}

void dfs(int u, int parent)
{
    tin[u] = ++counter;
    p[u][0] = parent;
    for (int i = 1; i <= l; i++)
    {
        p[u][i] = p[p[u][i - 1]][i - 1];
    }
    for (auto &child : adj[u])
    {
        if (child != parent)
        {
            depth[child] = depth[u] + 1;
            dfs(child, u);
        }
    }
    tout[u] = ++counter;
}

int get_dist(int u, int v)
{
    int common = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[common];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    depth[1] = 0;

    for (l = 1; (1 << l) <= n; l++)
        ;
    l -= 1;

    dfs(1, 1);

    int queries;
    cin >> queries;
    while (queries--)
    {
        int r, u, v;
        cin >> r >> u >> v;
        vector<pair<int, int>> t(6);
        t[0].second = r;
        t[1].second = u;
        t[2].second = v;
        t[3].second = lca(r, u);
        t[4].second = lca(r, v);
        t[5].second = lca(u, v);
        for (int i = 0; i < 6; i++)
        {
            int x = t[i].second;
            t[i].first = get_dist(x, r) + get_dist(x, u) + get_dist(x, v);
        }
        sort(t.begin(), t.end());
        cout << t[0].second << "\n";
    }

    return 0;
}
