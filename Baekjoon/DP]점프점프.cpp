//baekjoon 1890
//점프점프

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int board[101][101];
long long dp[101][101];

long long go(int i, int j)
{
    long long &ret = dp[i][j];
    if (ret != -1)
        return ret;
    if (i == n - 1 && j == n - 1)
        return 1;
    ret = 0;
    if (board[i][j] == 0)
        return ret;
    if (i + board[i][j] < n)
        ret += go(i + board[i][j], j);
    if (j + board[i][j] < n)
        ret += go(i, j + board[i][j]);
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    cout << go(0, 0);

    return 0;
}