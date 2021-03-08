// 2008 사다리게임
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n, m;
int dp[501][101]; // m, n
int a, b, del, add;
int edges[501];
const int inf = 1000000000;

int main()
{
    fill(&dp[0][0], &dp[500][100] + 1, inf);
    cin >> n >> m;
    cin >> a >> b >> del >> add;
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i];
    }
    dp[0][a] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == a)
            continue;
        dp[0][i] = abs(a - i) * add;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dp[i][j] != inf)
            {
                // cout<<dp[i][j]<<"("<<i<<" "<<j<<")"<<" ";
                int line = edges[i];
                for (int jj = 1; jj <= n; jj++)
                {
                    if (j == jj && (j == line || j == line + 1))
                    {
                        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + del);
                    }
                    else if ((jj <= line && line < j) || (line < jj && j <= line))
                    {
                        dp[i + 1][jj] = min(dp[i + 1][jj], dp[i][j] + add * (abs(j - jj) - 1));
                    }
                    else
                    {
                        dp[i + 1][jj] = min(dp[i + 1][jj], dp[i][j] + add * (abs(j - jj)));
                    }
                }
            }
        }
        // cout<<"\n";
    }
    cout << dp[m][b] << "\n";

    return 0;
}
