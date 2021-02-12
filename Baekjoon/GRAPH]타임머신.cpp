//11657 타임머신
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n, m;
struct Edge
{
    int dist;
    int from, to;
    Edge(int _dist, int _from, int _to) : dist(_dist), from(_from), to(_to)
    {
    }
};

vector<Edge> edges;
long long t[501];
long long inf = 100000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++)
    {
        t[i] = inf;
    }
    for (int i = 0; i < m; i++)
    {
        int from, to, dist;
        cin >> from >> to >> dist;
        edges.push_back(Edge(dist, from, to));
    }
    t[1] = 0;
    bool negative = false;
    for (int i = 1; i <= n; i++)
    {
        for (auto &child : edges)
        {
            if (t[child.from] != inf)
            {
                if (t[child.to] > t[child.from] + child.dist)
                {
                    t[child.to] = t[child.from] + child.dist;
                    if (i == n)
                    {
                        negative = true;
                    }
                }
            }
        }
    }
    if (negative)
    {
        cout << "-1" << '\n';
        return 0;
    }
    for (int i = 2; i <= n; i++)
    {
        if (t[i] == inf)
        {
            t[i] = -1;
        }
        cout << t[i] << "\n";
    }

    return 0;
}
