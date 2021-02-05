// 2056 작업
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int check[32001];
int indegree[32001] = {0};
vector<int> adj[32001];
int duration[32001];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t, ind;
        cin >> t >> ind;
        duration[i] = t;
        indegree[i] = ind;
        for (int j = 0; j < ind; j++)
        {
            int line;
            cin >> line;
            adj[line].push_back(i);
        }
    }
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(make_pair(i, duration[i]));
    }
    while (!q.empty())
    {
        int job, t;
        tie(job, t) = q.front();
        q.pop();
        t--;
        if (t != 0)
        {
            q.push(make_pair(job, t));
        }
        else
        {
            for (int &next : adj[job])
            {
                indegree[next]--;
                if (indegree[next] == 0)
                {
                    q.push(make_pair(next, duration[next]));
                    check[next] = check[job] + duration[job];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ans < check[i] + duration[i])
            ans = check[i] + duration[i];
    }
    cout << ans << "\n";
    return 0;
}
