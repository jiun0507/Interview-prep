//1753 최단경로
// baekjoon
// min heap (priority_queue)
#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int>> edges[20001];

int check[20001];
int dist[20001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(check, -1, sizeof(check));
    memset(dist, -1, sizeof(dist));
    int start;
    cin >> n;
    cin >> m;
    cin >> start;
    for (int i = 1; i <= m; i++)
    {
        int from, to, dist;
        cin >> from >> to >> dist;
        edges[from].push_back(make_pair(to, dist));
    }
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty())
    {
        int d, cur;
        tie(d, cur) = pq.top();
        pq.pop();
        if (check[cur] != -1 || d > dist[cur])
            continue;
        check[cur] = 1;
        for (auto &next : edges[cur])
        {
            if (dist[next.first] == -1 || dist[next.first] > dist[cur] + next.second)
            {
                dist[next.first] = dist[cur] + next.second;
                pq.push(make_pair(-dist[next.first], next.first));
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == -1)
        {
            cout << "INF\n";
            continue;
        }
        cout << dist[i] << "\n";
    }

    return 0;
}
