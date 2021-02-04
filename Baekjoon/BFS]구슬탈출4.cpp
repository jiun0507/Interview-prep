// 15653 구슬탈출 4
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n, m;
char board[11][11];
int check[11][11][11][11];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int sry, srx, sby, sbx;

pair<bool, bool> next(int &ry, int &rx, int &by, int &bx, int dir)
{
    bool red_hole = false;
    bool blue_hole = false;
    while (true)
    {
        ry = ry + dy[dir];
        rx = rx + dx[dir];
        by = by + dy[dir];
        bx = bx + dx[dir];
        if ((!red_hole && board[ry][rx] == '#') || board[by][bx] == '#')
        {
            bool red_moved = true;
            bool blue_moved = true;
            if (red_hole)
            {
                red_moved = false;
            }
            else if (board[ry][rx] == '#')
            {
                ry -= dy[dir];
                rx -= dx[dir];
                red_moved = false;
                if (by == ry && bx == rx)
                {
                    by -= dy[dir];
                    bx -= dx[dir];
                    break;
                }
            }
            if (board[by][bx] == '#')
            {
                by -= dy[dir];
                bx -= dx[dir];
                blue_moved = false;
                if (!red_hole && by == ry && bx == rx)
                {
                    ry -= dy[dir];
                    rx -= dx[dir];
                    break;
                }
            }
            if (!red_moved && !blue_moved)
            {
                break;
            }
        }
        if (board[by][bx] == 'O')
        {
            blue_hole = true;
            break;
        }
        if (!red_hole && board[ry][rx] == 'O')
        {
            red_hole = true;
            continue;
        }
    }
    return make_pair(red_hole, blue_hole);
}

int main()
{
    memset(check, -1, sizeof(check));
    sry = srx = sby = sbx = -1;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'R')
            {
                sry = i;
                srx = j;
                board[i][j] = '.';
            }
            else if (board[i][j] == 'B')
            {
                sby = i;
                sbx = j;
                board[i][j] = '.';
            }
        }
    }
    queue<tuple<int, int, int, int>> q; // ry rx by bx
    q.push(make_tuple(sry, srx, sby, sbx));
    check[sry][srx][sby][sbx] = 0;
    int ans = -1;

    while (!q.empty())
    {
        int ry, rx, by, bx;
        tie(ry, rx, by, bx) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nry = ry;
            int nrx = rx;
            int nby = by;
            int nbx = bx;
            bool hole1, hole2;
            tie(hole1, hole2) = next(nry, nrx, nby, nbx, i);
            if (hole2)
            {
                continue;
            }
            if (hole1)
            {
                bool found = true;
                cout << check[ry][rx][by][bx] + 1 << endl;
                return 0;
            }
            if (check[nry][nrx][nby][nbx] != -1)
                continue;
            check[nry][nrx][nby][nbx] = check[ry][rx][by][bx] + 1;
            q.push(make_tuple(nry, nrx, nby, nbx));
        }
    }
    cout << -1 << endl;
    return 0;
}
