//11437 LCA
// baekjoon
// using BFS
#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

vector<int> adj[50001];
int parent[50001];
int depth[50001];
bool check[50001] = {false};
int n, m;

int main()
{
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

    cin >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
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
            cout << a << endl;
        }
        else if (a == 1 || b == 1)
        {
            cout << 1 << endl;
        }
    }
    return 0;
}
