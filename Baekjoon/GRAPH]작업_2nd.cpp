// 2056 작업
// baekjoon

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int degree[10001];
vector<int> neighbors[10001];
int cost[10001];
int start[10001];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        int neighbor;
        cin >> neighbor;
        for (int j = 0; j < neighbor; j++)
        {
            int buf;
            cin >> buf;
            neighbors[buf].push_back(i);
            degree[i]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] == 0)
        {
            q.push(i);
        }
    }
    int ans = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (ans < start[cur] + cost[cur])
        {
            ans = start[cur] + cost[cur];
        }
        for (int next : neighbors[cur])
        {
            degree[next]--;
            start[next] = max(start[next], start[cur] + cost[cur]);
            if (degree[next] == 0)
            {
                q.push(next);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
