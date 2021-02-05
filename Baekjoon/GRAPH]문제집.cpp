// 1766 문제집
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
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            pq.push(i);
    }
    vector<int> ans;
    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        ans.push_back(cur);
        for (int &next : adj[cur])
        {
            indegree[next]--;
            if (indegree[next] == 0)
            {
                pq.push(next);
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
