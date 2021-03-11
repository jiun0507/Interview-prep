// 1126 같은 탑
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n;
int num[51];
int dp[500001][51];

int main()
{
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        total += num[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < total; j++)
        {
            if (dp[j][i] != -1)
            {
                // cout<<j<<" "<<i<<" : "<<dp[j][i]<<"\n";
                dp[j + num[i]][i + 1] = max(dp[j + num[i]][i + 1], dp[j][i]);
                if (j > num[i])
                {
                    dp[j - num[i]][i + 1] = max(dp[j - num[i]][i + 1], dp[j][i] + num[i]);
                }
                else if (j < num[i])
                {
                    dp[num[i] - j][i + 1] = max(dp[num[i] - j][i + 1], dp[j][i] + j);
                }
                else
                {
                    dp[0][i + 1] = max(dp[0][i + 1], dp[j][i] + num[i]);
                }
                dp[j][i + 1] = max(dp[j][i + 1], dp[j][i]);
            }
        }
    }
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dp[0][i] > mx)
        {
            mx = dp[0][i];
        }
    }
    if (mx == 0)
    {
        cout << "-1\n";
        return 0;
    }

    cout << mx << "\n";

    return 0;
}
