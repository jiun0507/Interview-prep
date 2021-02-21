// 2228 구간 나누기
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int dp[103][101];
int n, m;
int psum[103];
const int inf = 1000000007;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            cin >> psum[i];
        else
        {
            cin >> psum[i];
            psum[i] += psum[i - 1];
        }
    }
    fill(&dp[0][0], &dp[102][100] + 1, -inf);

    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dp[i][j] == -inf)
                continue;
            if (dp[i + 1][j] < dp[i][j])
                dp[i + 1][j] = dp[i][j];
            for (int k = i; k < n; k++)
            {
                int val = psum[k];
                int minus = 0;
                if (i != 0)
                    minus = psum[i - 1];
                val -= minus;
                // cout<<k+2<<" "<<j+1<<" "<<dp[i][j] + val<<endl;
                if (dp[k + 2][j + 1] < dp[i][j] + val)
                    dp[k + 2][j + 1] = dp[i][j] + val;
            }
        }
    }
    int ans = -inf;
    for (int i = 0; i <= n + 1; i++)
    {
        if (dp[i][m] > ans)
        {
            ans = dp[i][m];
        }
    }
    cout << ans << "\n";
    return 0;
}
