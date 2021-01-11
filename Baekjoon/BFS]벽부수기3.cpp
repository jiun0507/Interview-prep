// 16993
// baekjoon 벽부수기 3
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n, m, k;
int dy[5] = {0, 0, 1, -1, 0};
int dx[5] = {1, -1, 0, 0, 0};
int check[1001][1001][11][2] = {0};
int board[1001][1001] = {0};

void bfs()
{
    tuple<int, int, int, int> start = make_tuple(0, 0, 0, 0);
    deque<tuple<int, int, int, int>> next;
    next.push_back(start);
    check[0][0][0][0] = 1;
    while (!next.empty())
    {
        auto cur = next.front();
        int y = get<0>(cur);
        int x = get<1>(cur);
        int wall = get<2>(cur);
        int now = get<3>(cur);

        next.pop_front();
        for (int i = 0; i < 5; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int later = (now + 1) % 2;
            if (ny >= 0 && ny < n && nx >= 0 && nx < m)
            {
                if (board[ny][nx] == 0 && check[ny][nx][wall][later] == 0)
                {
                    check[ny][nx][wall][later] = check[y][x][wall][now] + 1;
                    next.push_back(make_tuple(ny, nx, wall, later));
                }
                else
                {
                    if (i == 4 && check[ny][nx][wall][later] == 0)
                    {
                        check[ny][nx][wall][later] = check[y][x][wall][now] + 1;
                        next.push_back(make_tuple(ny, nx, wall, later));
                    }
                    if (now == 1)
                        continue;
                    if (wall < k && check[ny][nx][wall + 1][later] == 0)
                    {
                        check[ny][nx][wall + 1][later] = check[y][x][wall][now] + 1;
                        next.push_back(make_tuple(ny, nx, wall + 1, later));
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    string line;
    for (int i = 0; i < n; i++)
    {
        cin >> line;
        for (int j = 0; j < m; j++)
        {
            if (line.at(j) == '0')
                board[i][j] = 0;
            else
            {
                board[i][j] = 1;
            }
        }
    }
    bfs();

    int ans = -1;
    for (int day = 0; day < 2; day++)
    {
        for (int i = 0; i <= k; i++)
        {
            int arrived = check[n - 1][m - 1][i][day];
            if (arrived != 0)
            {
                if (ans == -1 || arrived < ans)
                    ans = arrived;
            }
        }
    }

    cout << ans << endl;
    return 0;
}