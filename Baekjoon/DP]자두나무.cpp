// 2240 자두나무
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int dp[1002][31];
int fall[1002];
int t, w;

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> t >> w;
    for (int i = 0; i < t; i++)
    {
        cin >> fall[i];
    }
    dp[0][0] = 0;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (dp[i][j] != -1)
            {
                int caught = (j % 2 + 1) == fall[i];
                if (dp[i + 1][j] < dp[i][j] + caught)
                    dp[i + 1][j] = dp[i][j] + caught;
                if (j < w)
                {
                    caught = (caught + 1) % 2;
                    if (dp[i + 1][j + 1] < dp[i][j] + caught)
                    {
                        dp[i + 1][j + 1] = dp[i][j] + caught;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= w; i++)
    {
        if (ans < dp[t][i])
        {
            ans = dp[t][i];
        }
    }
    cout << ans << "\n";
    return 0;
}
