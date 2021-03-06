// 2172 팰린드롬 경로
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n, l;
int dp[22][21][21][21][21]; // L, sy, sx, ey, ex
int board[21][21];
int dy[9] = {1, 1, 1, 0, 0, -1, -1, -1, 0};
int dx[9] = {1, 0, -1, 1, -1, 1, 0, -1, 0};

int main()
{
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[1][i][j][i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int dir = 0; dir < 8; dir++)
            {
                int k = i + dy[dir];
                int m = j + dx[dir];
                if (k < 0 || k >= n || m < 0 || m >= n)
                    continue;
                if (i == k && j == m)
                    continue;
                if (board[i][j] == board[k][m])
                {
                    dp[2][i][j][k][m] = 1;
                }
            }
        }
    }
    for (int len = 1; len < l; len++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    for (int m = 0; m < n; m++)
                    {
                        if (dp[len][i][j][k][m] == 0)
                            continue;
                        // cout<<i<<" "<<j<<" "<<k<<" "<<m<<" "<<dp[len][i][j][k][m]<<"\n";
                        for (int dir_start = 0; dir_start < 8; dir_start++)
                        {
                            for (int dir_end = 0; dir_end < 8; dir_end++)
                            {
                                int sy = i + dy[dir_start];
                                int sx = j + dx[dir_start];
                                int ey = k + dy[dir_end];
                                int ex = m + dx[dir_end];
                                if (sy >= 0 && sy < n && sx >= 0 && sx < n && ey >= 0 && ey < n && ex >= 0 && ex < n)
                                {
                                    if (board[sy][sx] == board[ey][ex])
                                    {
                                        dp[len + 2][sy][sx][ey][ex] += dp[len][i][j][k][m];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int m = 0; m < n; m++)
                {
                    ret += dp[l][i][j][k][m];
                }
            }
        }
    }
    cout << ret << "\n";
    return 0;
}
