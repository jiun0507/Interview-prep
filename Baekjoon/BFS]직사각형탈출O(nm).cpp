// 16973 직사각형 탈출
// baekjoon

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main(void)
{
    int ps[1001][1001];
    bool board[1001][1001];
    int check[1001][1001];
    memset(check, -1, sizeof(check));
    int n, m, h, w, sr, sc, fr, fc;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> board[i][j];
            ps[i][j] = board[i][j] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
        }
    }
    cin >> h >> w >> sr >> sc >> fr >> fc;
    queue<pair<int, int>> q;
    q.push(make_pair(sr, sc));
    check[sr][sc] = 0;
    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        int y = now.first;
        int x = now.second;
        if (y == fr && x == fc)
            break;
        for (int i = 0; i < 4; i++)
        {
            int newy = y + dy[i];
            int newx = x + dx[i];
            if (newy >= 1 && newy + h - 1 <= n && newx >= 1 && newx + w - 1 <= m)
            {
                if (check[newy][newx] != -1)
                    continue;
                bool blocked = false;
                int walls = ps[newy + h - 1][newx + w - 1] + ps[newy - 1][newx - 1] - ps[newy - 1][newx + w - 1] - ps[newy + h - 1][newx - 1] > 0;
                if (walls == 0)
                {
                    q.push(make_pair(newy, newx));
                    check[newy][newx] = check[y][x] + 1;
                }
                else
                {
                    check[newy][newx] = -2;
                }
            }
        }
    }
    if (check[fr][fc] != -1 && check[fr][fc] != -2)
    {
        cout << check[fr][fc];
    }
    else
    {
        cout << -1;
    }

    return 0;
}