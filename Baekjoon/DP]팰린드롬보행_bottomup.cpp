// 12950 팰린드롬 보행
// baekjoon
#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n, m;
int dp[21][21]; // s, e
int edges[21][21];
const int inf = 1000000000;

int main()
{
    memset(edges, -1, sizeof(edges));
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = inf;
        }
        dp[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;
        edges[a][b] = c - 'a';
        edges[b][a] = c - 'a';
        dp[a][b] = 1;
        dp[b][a] = 1;
    }

    for (int l = 0; l < 400; l++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][j] != inf)
                    ;
                for (int ii = 0; ii < n; ii++)
                {
                    for (int jj = 0; jj < n; jj++)
                    {
                        if (edges[i][ii] != -1 && edges[i][ii] == edges[j][jj])
                        {
                            dp[ii][jj] = min(dp[ii][jj], 2 + dp[i][j]);
                        }
                    }
                }
            }
        }
    }
    if (dp[0][1] == inf)
    {
        cout << "-1\n";
    }
    else
    {
        cout << dp[0][1] << "\n";
    }

    return 0;
}
