// 1761 정점들이 거리
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[50001];
int parent[50001];
int depth[50001];
int dist[50001];
bool check[50001] = {false};
int n, m;

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b, weight;
        cin >> a >> b >> weight;
        adj[a].push_back(make_pair(b, weight));
        adj[b].push_back(make_pair(a, weight));
    }

    queue<int> q;
    check[1] = true;
    depth[1] = 0;
    parent[1] = 0;
    dist[1] = 0;
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
            parent[child.first] = cur;
            depth[child.first] = depth[cur] + 1;

            dist[child.first] = dist[cur] + child.second;
            q.push(child.first);
        }
    }

    cin >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        int original_a, original_b;
        original_b = b;
        original_a = a;
        while (depth[a] != depth[b])
        {
            if (depth[a] > depth[b])
            {
                a = parent[a];
            }
            else
            {
                b = parent[b];
            }
        }
        while (a != b)
        {
            a = parent[a];
            b = parent[b];
        }
        if (a == b)
        {
            cout << dist[original_a] + dist[original_b] - 2 * dist[a] << endl;
        }
    }
    return 0;
}
