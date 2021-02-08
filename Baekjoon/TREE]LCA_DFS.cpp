// 11437 LCA
// baekjoon
// DFS method

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

vector<int> adj[50001];
int parent[50001];
int depth[50001];
bool check[50001] = {false};
int n, m;

void traverse(int here, int d)
{
    depth[here] = d;
    check[here] = true;
    for (auto &child : adj[here])
    {
        if (check[child] == 1)
            continue;
        parent[child] = here;
        traverse(child, d + 1);
    }
}

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

    traverse(1, 0);

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
