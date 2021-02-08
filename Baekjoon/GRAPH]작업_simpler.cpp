// 2056 작업
// baekjoon

// t를 하나씩 줄이지 않고 한꺼번에 줄이는 방법. -> 더 빠르다.

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
        for (int &next : adj[job])
        {
            indegree[next]--;
            if (check[next] < check[job] + duration[job])
                check[next] = check[job] + duration[job];
            if (indegree[next] == 0)
            {
                q.push(make_pair(next, duration[next]));
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
