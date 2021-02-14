// 1520 내리막길
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int p[501][501];
int board[501][501];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
int n, m;

void dfs(int i, int j)
{
    if (p[i][j] != -1 || (i == n - 1 && j == m - 1))
        return;
    p[i][j] = 0;
    for (int k = 0; k < 4; k++)
    {
        int ny = i + dy[k];
        int nx = j + dx[k];
        if (ny >= 0 && ny < n && nx >= 0 && nx < m)
        {
            if (board[i][j] <= board[ny][nx])
                continue;
            if (p[ny][nx] == -1)
                dfs(ny, nx);
            p[i][j] += p[ny][nx];
        }
    }
    cout << i << " " << j << ":" << p[i][j] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    memset(p, -1, sizeof(p));
    p[n - 1][m - 1] = 1;
    dfs(0, 0);
    cout << p[0][0] << "\n";

    return 0;
}
