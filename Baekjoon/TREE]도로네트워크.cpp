//3176 도로 네트워크
// baekjoon
// using BFS
#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

const int MAX = 200001;
int p[MAX][17];
vector<pair<int, int>> adj[MAX];
int len_min[MAX][17];
int len_max[MAX][17];
bool check[MAX];
int depth[MAX];
int n, m;

const pair<int, int> lca(int u, int v)
{
    int minimum = 1000001;
    int maximum = -1;
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
            maximum = max(maximum, len_max[u][i]);
            minimum = min(minimum, len_min[u][i]);
            u = p[u][i];
        }
    }
    if (u == v)
    {
        return make_pair(minimum, maximum);
    }
    else
    {
        for (int i = log; i >= 0; i--)
        {
            if (p[u][i] != 0 && p[u][i] != p[v][i])
            {
                maximum = max(maximum, len_max[u][i]);
                minimum = min(minimum, len_min[u][i]);
                maximum = max(maximum, len_max[v][i]);
                minimum = min(minimum, len_min[v][i]);
                u = p[u][i];
                v = p[v][i];
            }
        }
        maximum = max(maximum, len_max[u][0]);
        minimum = min(minimum, len_min[u][0]);
        maximum = max(maximum, len_max[v][0]);
        minimum = min(minimum, len_min[v][0]);
        return make_pair(minimum, maximum);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, dist;
        cin >> a >> b >> dist;
        adj[a].push_back(make_pair(b, dist));
        adj[b].push_back(make_pair(a, dist));
    }
    queue<int> q;
    check[1] = true;
    depth[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        check[cur] = true;
        for (auto &child : adj[cur])
        {
            if (check[child.first] == true)
                continue;
            p[child.first][0] = cur;
            len_min[child.first][0] = child.second;
            len_max[child.first][0] = child.second;
            len_min[child.first][0] = child.second;
            len_max[child.first][0] = child.second;
            depth[child.first] = depth[cur] + 1;
            q.push(child.first);
        }
    }
    for (int i = 1; i < 17; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int ancestor_number = p[j][i - 1];
            int anc_min = len_min[j][i - 1];
            int anc_max = len_max[j][i - 1];
            int deep_min = len_min[ancestor_number][i - 1];
            int deep_max = len_max[ancestor_number][i - 1];
            p[j][i] = p[ancestor_number][i - 1];
            len_min[j][i] = min(anc_min, deep_min);
            len_max[j][i] = max(anc_max, deep_max);
        }
    }
    int queries;
    cin >> queries;
    while (queries--)
    {
        int u, v;
        cin >> u >> v;
        auto &ans = lca(u, v);
        cout << ans.first << " " << ans.second << "\n";
    }

    return 0;
}
