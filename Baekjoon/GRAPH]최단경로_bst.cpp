//1753 최단경로
//baekjoon
//bst (set)
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
    set<pair<int, int>> s;
    s.insert(make_pair(0, start));
    while (!s.empty())
    {
        auto p = *s.begin();
        s.erase(s.begin());
        int cur = p.second;
        if (check[cur] != -1)
            continue;
        check[cur] = 1;
        for (auto &next : edges[cur])
        {
            if (dist[next.first] == -1 || dist[next.first] > dist[cur] + next.second)
            {
                if (dist[next.first] != -1)
                {
                    s.erase(s.find(make_pair(dist[next.first], next.first)));
                }
                dist[next.first] = dist[cur] + next.second;
                s.insert(make_pair(dist[next.first], next.first));
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
