// 2252 줄세우기
// baekjoon

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int degree[32001];
vector<int> neighbors[32001];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        degree[b]++;
        neighbors[a].push_back(b);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (int next : neighbors[cur])
        {
            degree[next]--;
            if (degree[next] == 0)
            {
                q.push(next);
            }
        }
    }

    cout << "\n";
    return 0;
}
