//11438 LCA2
// baekjoon
// using log approach
#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

const int MAX = 100111;
vector<int> adj[MAX];
int parent[MAX];
bool check[MAX];
int depth[MAX];
int p[MAX][17];
int n, m;

int lca(int u, int v)
{
    if (depth[u] < depth[v])
    {
        swap(u, v);
    }
    int log = 1;
    for (log = 1; (1 << log) <= depth[u]; log++)
        ;
    log -= 1;
    for (int i = log; i >= 0; i--)
    {
        if (depth[u] - (1 << i) >= depth[v])
        {
            u = p[u][i];
        }
    }
    if (u == v)
    {
        return u;
    }
    else
    {
        for (int i = log; i >= 0; i--)
        {
            if (p[u][i] != 0 && p[u][i] != p[v][i])
            {
                u = p[u][i];
                v = p[v][i];
            }
        }
        return parent[u];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    check[1] = true;
    depth[1] = 0;
    parent[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        check[cur] = true;
        for (auto &child : adj[cur])
        {
            if (check[child] == true)
                continue;
            parent[child] = cur;
            depth[child] = depth[cur] + 1;
            q.push(child);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        p[i][0] = parent[i];
    }
    for (int j = 1; (1 << j) < n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (p[i][j - 1] != 0)
            {
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }
    }
    cin >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
    return 0;
}
