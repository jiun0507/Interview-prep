// 16973 직사각형 탈출
// baekjoon

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int board[1001][1001];
int dp[1001][1001];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i > 0)
            {
                board[i][j] += board[i - 1][j];
            }
            if (j > 0)
            {
                board[i][j] += board[i][j - 1];
            }
            if (i > 0 && j > 0)
                board[i][j] -= board[i - 1][j - 1];
            int buf;
            cin >> buf;
            board[i][j] += buf;
            // cout<<board[i][j]<<" ";
        }
        // cout<<"\n";
    }
    int h, w, sr, sc, fr, fc;
    cin >> h >> w >> sr >> sc >> fr >> fc;
    memset(dp, -1, sizeof(dp));
    sr -= 1;
    sc -= 1;
    fr -= 1;
    fc -= 1;
    dp[sr][sc] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(sr, sc));
    while (!q.empty())
    {
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        if (y == fr && x == fc)
        {
            cout << dp[y][x] << "\n";
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (ny + h - 1 < 0 || ny + h - 1 >= n || nx + w - 1 < 0 || nx + w - 1 >= m)
                continue;
            if (dp[ny][nx] == -1)
            {
                int total = board[ny + h - 1][nx + w - 1];
                if (ny > 0)
                {
                    total -= board[ny - 1][nx + w - 1];
                }
                if (nx > 0)
                {
                    total -= board[ny + h - 1][nx - 1];
                }
                if (ny > 0 && nx > 0)
                {
                    total += board[ny - 1][nx - 1];
                }
                if (total == 0)
                {
                    dp[ny][nx] = dp[y][x] + 1;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
    cout << "-1\n";
    return 0;
}
