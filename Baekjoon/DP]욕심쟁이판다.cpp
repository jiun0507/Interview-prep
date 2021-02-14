// 1937 욕심쟁이 판다
// baekjoon
// using DFS

// dp[i][j] = i,j 에서 먹기 시작 할 떄 몇일 동안 살아남을 수 있는지.
// bfs를 쓰면은 시작점부터 i, j까지의 거리를 구하게 되고 dfs를 쓰면 i,j부터 끝점까지 구할 수 있으므로 dfs를 사용해서
// dp를 적용한다.

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int p[501][501];
int board[501][501];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
int n;

int dfs(int i, int j)
{
    p[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        int ny = i + dy[k];
        int nx = j + dx[k];
        if (ny >= 0 && ny < n && nx >= 0 && nx < n)
        {
            if (board[i][j] >= board[ny][nx])
                continue;
            if (p[ny][nx] != -1)
            {
                p[i][j] = max(p[i][j], p[ny][nx] + 1);
            }
            else if (p[ny][nx] == -1)
            {
                dfs(ny, nx);
                p[i][j] = max(p[i][j], p[ny][nx] + 1);
            }
        }
    }
    return p[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    memset(p, -1, sizeof(p));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (p[i][j] == -1)
            {
                dfs(i, j);
            }
            ans = max(ans, p[i][j]);
        }
    }
    cout << ans << "\n";

    return 0;
}
