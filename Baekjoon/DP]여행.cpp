// 2157 여행
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int dp[302][302];
int n, m, k;
int path[302][302];
vector<int> path_list[302];

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {

        int from, to, dist;
        cin >> from >> to >> dist;
        if (to < from)
            continue;
        if (path[from][to] != 0 && path[from][to] > dist)
            continue;
        path[from][to] = dist;
        path_list[from].push_back(to);
    }
    memset(dp, -1, sizeof(dp));

    dp[1][1] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (dp[i][j] == -1)
                continue;
            for (auto next : path_list[i])
            {
                if (dp[next][j + 1] < dp[i][j] + path[i][next])
                {
                    dp[next][j + 1] = dp[i][j] + path[i][next];
                }
            }
        }
    }
    int ans = 0;
    for (int j = 1; j <= m; j++)
    {
        if (ans < dp[n][j])
            ans = dp[n][j];
    }
    cout << ans << "\n";
    return 0;
}
