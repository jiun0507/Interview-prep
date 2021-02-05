// 2252 줄 세우기
// baekjoon
#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int indegree[32000] = {0};
vector<int> adj[32000];
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        indegree[b - 1]++;
        adj[a - 1].push_back(b - 1);
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for (int &next : adj[cur])
        {
            indegree[next]--;
            if (indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";
    return 0;
}
