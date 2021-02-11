//1922 네트워크 연결
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int adj[1001][1001];
int check[1001];
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cin >> m;
    memset(adj, -1, sizeof(adj));
    memset(check, -1, sizeof(check));
    for (int i = 0; i < m; i++)
    {
        int a, b, dist;
        cin >> a >> b >> dist;
        adj[a][b] = dist;
        adj[b][a] = dist;
    }
    priority_queue<pair<int, int>> pq;

    check[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (adj[1][i] != -1)
        {
            pq.push(make_pair(-adj[1][i], i));
        }
    }
    int ans = 0;
    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        int now = cur.second;
        if (check[now] != -1)
        {
            pq.pop();
            continue;
        }
        ans -= cur.first;
        check[now] = 1;
        pq.pop();
        for (int i = 1; i <= n; i++)
        {
            if (check[i] == -1 && adj[now][i] != -1)
            {
                pq.push(make_pair(-adj[now][i], i));
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
