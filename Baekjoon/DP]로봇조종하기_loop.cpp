// 2169 로봇 조종하기
// baekjoon

// dp[i][j][dir] = dir으로 갈 수 있는 상태로 i, j까지 올때 탐색할 수 있는 최대 숫자.
// dir: 0아래 오른쪽 왼쪽 모두 갈 수 있다. 1 왼쪽 못간다. 2 오른쪽 못 간다.

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int dp[1010][1010][3];
int n, m;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
int board[1010][1010];
const int minimum = -100000007;

int go(int y, int x, int dir)
{
    if (y == n - 1 && x == m - 1)
    {
        return board[y][x];
    }
    if (dp[y][x][dir] != minimum)
    {
        return dp[y][x][dir];
    }
    int ret = minimum;
    if (y < n - 1)
        ret = go(y + 1, x, 0);
    if (x < m - 1 && dir != 2)
    { //2 is only left
        ret = max(ret, go(y, x + 1, 1));
    }
    if (x > 0 && dir != 1)
    { //1 is only right
        ret = max(ret, go(y, x - 1, 2));
    }
    dp[y][x][dir] = ret + board[y][x];
    return dp[y][x][dir];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    fill(&dp[0][0][0], &dp[1009][1009][2] + 1, minimum);
    dp[0][0][0] = dp[0][0][1] = board[0][0];
    for (int i = 1; i < m; i++)
        dp[0][i][1] = board[0][i] + dp[0][i - 1][1];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j][0] = max({dp[i - 1][j][0], dp[i - 1][j][1], dp[i - 1][j][2]}) + board[i][j];
            if (j > 0)
                dp[i][j][1] = max(dp[i][j - 1][0], dp[i][j - 1][1]) + board[i][j];
        }
        for (int j = m - 2; j >= 0; j--)
        {
            dp[i][j][2] = max(dp[i][j + 1][0], dp[i][j + 1][2]) + board[i][j];
        }
    }
    cout << max({dp[n - 1][m - 1][0], dp[n - 1][m - 1][1], dp[n - 1][m - 1][2]}) << "\n";
    return 0;
}
