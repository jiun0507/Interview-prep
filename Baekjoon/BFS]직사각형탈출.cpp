// 16973 직사각형 탈출
// baekjoon

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main(void)
{
    bool board[1001][1001];
    int check[1001][1001];
    memset(check, -1, sizeof(check));
    vector<pair<int, int>> walls;
    int n, m, h, w, sr, sc, fr, fc;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                walls.push_back(make_pair(i, j));
            }
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
                for (auto &wall : walls)
                {
                    if (wall.first >= newy && wall.first < newy + h && wall.second >= newx && wall.second < newx + w)
                    {
                        blocked = true;
                        break;
                    }
                }
                if (!blocked)
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